#include "data_struction.h"
#include "fixedQueue.h"
#include "EKF/FusionEKF.h"
#include "EKF/measurement_package.h"
#include "visualization_tool/visualization_tool.h"
#include "RCA/Ray_Casting_Algorithm.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2,sensor_msgs::PointCloud2, geometry_msgs::PoseStamped> MySyncPolicy;
typedef message_filters::Synchronizer<MySyncPolicy> Sync;

class Object_Detection{
private:
    ros::NodeHandle nh;
    message_filters::Subscriber<sensor_msgs::PointCloud2> subNonGroundCloud;
    message_filters::Subscriber<sensor_msgs::PointCloud2> subGroundCloud;
    message_filters::Subscriber<geometry_msgs::PoseStamped> subLocal;
    boost::shared_ptr<Sync> sync;
    
    ros::Publisher pubROICloud; // 도로에 해당하는 point cloud 중 차량의 최소회전 반경을  고려한 point cloud
    ros::Publisher pubObjCenter;
    ros::Publisher pubObjBoundary;
    ros::Publisher pubVector;
    ros::Publisher pubOuter;
    ros::Publisher pubNearestInner;

    pcl::PointCloud<PointType>::Ptr groundCloudIn;// patchwork++에 의해 들어온 ground cloud를 저장
    pcl::PointCloud<PointType>::Ptr nongroundCloudIn;// patchwork++에 의해 들어온  non ground cloud를 저장

    vector<pcl::PointCloud<PointType>::Ptr> ObjCandidateCloud[2];

    pcl::PointCloud<PointType>::Ptr Clustered_Cloud;// 클러스터링된 cloud
    pcl::PointCloud<PointType>::Ptr ROICloud;// 클러스터링된 cloud중 z값이 0 이하인 점들만 남김

    visualization_msgs::MarkerArray obj_boundary_markerarray;    
    visualization_msgs::MarkerArray obj_center_markerarray;    
    visualization_msgs::MarkerArray normal_vectors;    
    visualization_msgs::MarkerArray outer_zone;    
    visualization_msgs::MarkerArray nearest_inner_zone;    

    vector<Object_info> obj_center_point;
    vector<PointType> lastest_cones;

    std_msgs::Header cloudHeader;
    pcl::KdTreeFLANN<PointType> Ground_kdtree;
    
    Ego_status ego_info;
    
    vector<FusionEKF> EKFs;
    vector<VectorXd> pred_position;
    vector<MeasurementPackage> measurement_pack_list;
    MeasurementPackage meas_package;

    vector<int> id_list;
    
    Visualization_tool Vt;
    Ray_Casting_Algorithm RCA;

    Polygon outer; 

    vector<Polygon> inners;
    vector<Polygon> near_ego_inners;

    int cone_id=0;
    int count =0;
    float dx, dy, dyaw;
public:

    Object_Detection():
        nh("~"){

        subNonGroundCloud.subscribe(nh, "/ground_segmentation/nonground", 1);
        subGroundCloud.subscribe(nh, "/ground_segmentation/ground", 1);
        subLocal.subscribe(nh, "/local_msgs_for_vision2", 10);
         
        sync.reset(new Sync(MySyncPolicy(50), subNonGroundCloud, subGroundCloud, subLocal));
        sync->registerCallback(boost::bind(&Object_Detection::cloudHandler, this, _1, _2, _3));

        pubROICloud = nh.advertise<sensor_msgs::PointCloud2> ("/ROI_cloud", 1);

        pubObjCenter = nh.advertise<visualization_msgs::MarkerArray>("/cone_center_markers", 1);
        pubObjBoundary = nh.advertise<visualization_msgs::MarkerArray>("/cone_BoundingBox", 1);
        pubVector =  nh.advertise<visualization_msgs::MarkerArray>("/vectors", 1);
        
        pubOuter  =  nh.advertise<visualization_msgs::MarkerArray>("/outer_zone", 1);
        pubNearestInner =  nh.advertise<visualization_msgs::MarkerArray>("/nearest_Inner_zone", 1);

        allocateMemory();
        resetParameters();
    }

    void allocateMemory(){

        groundCloudIn.reset(new pcl::PointCloud<PointType>());
        nongroundCloudIn.reset(new pcl::PointCloud<PointType>());
        ROICloud.reset(new pcl::PointCloud<PointType>());

        Clustered_Cloud.reset(new pcl::PointCloud<PointType>());
        
        pred_position.resize(1000, Eigen::VectorXd::Zero(4));
        measurement_pack_list.resize(1000);
        meas_package.raw_measurements_ = VectorXd(2);
        EKFs.resize(1000);

        lastest_cones.resize(10000);

        obj_center_markerarray.markers.clear();
        obj_boundary_markerarray.markers.clear();
        normal_vectors.markers.clear();
        outer_zone.markers.clear();
        nearest_inner_zone.markers.clear();

        outer = RCA.readOuterPolygon();
        inners = RCA.readInnerPolygon();
    }

    void resetParameters(){
        groundCloudIn->clear();
        nongroundCloudIn->clear();
        
        for(int i=0; i<2; i++)
            ObjCandidateCloud[i].clear();

        ROICloud->clear();

        id_list.clear();
        obj_center_point.clear();
        Clustered_Cloud->clear();
        
        obj_center_markerarray.markers.clear();
        obj_boundary_markerarray.markers.clear();
        normal_vectors.markers.clear();
        outer_zone.markers.clear();
        nearest_inner_zone.markers.clear();
        
        near_ego_inners.clear();

        count++;
    }

    ~Object_Detection(){}
    
    void groundcloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
        
        pcl::fromROSMsg(*laserCloudMsg, *groundCloudIn);

        Ground_kdtree.setInputCloud(groundCloudIn);
    }

    void localMsgHandler(const geometry_msgs::PoseStamped::ConstPtr& localMsg){
        if(ego_info.is_initialize){ 
            ego_info.prev = ego_info.curr;
        }

        ego_info.curr.x = localMsg->pose.position.x;

        ego_info.curr.y = localMsg->pose.position.y;

        ego_info.roll = localMsg->pose.orientation.x;

        ego_info.pitch = localMsg->pose.orientation.y;

        ego_info.yaw = localMsg->pose.orientation.z;

        
    }

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;
        cloudHeader.frame_id = "base_link";
        cloudHeader.stamp = ros::Time::now(); 
        pcl::fromROSMsg(*laserCloudMsg, *nongroundCloudIn);

        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*nongroundCloudIn, *nongroundCloudIn, indices);
        
    }

    void cloudHandler(const boost::shared_ptr<const sensor_msgs::PointCloud2>& laserCloudMsg,
                    const boost::shared_ptr<const sensor_msgs::PointCloud2>& GroundlaserCloudMsg,
                    const boost::shared_ptr<const geometry_msgs::PoseStamped>& LocalMsg ){
        //data processing
        groundcloudHandler(GroundlaserCloudMsg);
        
        localMsgHandler(LocalMsg);
        
        copyPointCloud(laserCloudMsg);
        //
        auto start_time = std::chrono::high_resolution_clock::now();
        
        //get ROICloud with RCA
        near_ego_inners = RCA.get_nearest_N_inner_zone(6,inners,ego_info);

        RCA.set_ROI_RCA(nongroundCloudIn, ROICloud,outer,near_ego_inners,ego_info);
        //

        //Object Detection
        clustering(ROICloud,ObjCandidateCloud[0], 1.0 , 20, 800);
        
        set_ROI(ObjCandidateCloud[0]);
        
        detect_object(ObjCandidateCloud[1]);
        //

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        ROS_INFO_STREAM("\033[1;32m" << "OD Working... process time:: "<<duration.count() << " ms" <<  "\033[0m");

        publishCloud();

        resetParameters();
    }

    void detect_object(vector<pcl::PointCloud<PointType>::Ptr> input_cloud_vec){
        int count =0;

        for (auto iter = input_cloud_vec.begin(); iter != input_cloud_vec.end(); ++iter){
            pcl::CentroidPoint<PointType> centroid;

            size_t cloud_size = (*iter)->points.size();
            
            
            for(int i=0; i< cloud_size; i++){
                PointType thispoint = (*iter)->points[i];
                centroid.add(thispoint);
            }
            //clustered point의 중간값을 계산
            PointType c1;
            centroid.get(c1);

            // kd-tree를 활용해 중심점의 2m 반경 내의 지면 PC를 추출
            std::vector<int> indices;
            std::vector<float> distances;
            pcl::PointCloud<PointType>::Ptr tmp_ground(new pcl::PointCloud<PointType>);

            float ground_min_z = 0.0; //우선 센서 높이를 기본값으로 설정

            if(Ground_kdtree.radiusSearch(c1,2.0,indices, distances) > 0){
                int count = 0;

                for (size_t j = 0; j < indices.size(); ++j) {

                    if(ground_min_z >  groundCloudIn->points[indices[j]].z){
                        ground_min_z = groundCloudIn->points[indices[j]].z;
                    }
                    
                    tmp_ground->push_back(groundCloudIn->points[indices[j]]);
                }

            }
             
            // 지면 일부분 point cloud에서 얻은 법선 벡터와 콘의 주축 벡터를 활용해 각도를 계산
            VectorXf ground_normal(3,1);
            if(tmp_ground->points.size() > 20) ground_normal = conduct_PCA(tmp_ground,2);
            else {
                ground_normal[0] =0;ground_normal[1] =0;ground_normal[2] =1;
            }

            VectorXf cone_principle_vec = conduct_PCA((*iter),0);

            if (pubVector.getNumSubscribers() != 0){
                Vt.visual_vector(c1,vector2point(cone_principle_vec,c1), 1.0, 1.0, 1.0,count,obj_center_point, normal_vectors,"map");
                Vt.visual_vector(c1,vector2point(ground_normal,c1), 0.0, 0.0,1.0,count+100,obj_center_point,normal_vectors,"map");
                pubVector.publish(normal_vectors);
            }

            double diff_angle = (acos(ground_normal.dot(cone_principle_vec)) /(magnitude(ground_normal)*magnitude(cone_principle_vec)))*180/PI;
            if(diff_angle < 85 || diff_angle > 95){
               
                //clustered point의 최대 최소값
                PointType maxPoint,minPoint;
                pcl::getMinMax3D(*(*iter), minPoint, maxPoint);
                        
                Object_info cone_info;
                cone_info.max_point = maxPoint;
                cone_info.min_point = minPoint;
                cone_info.mid_point = c1;

                obj_center_point.push_back(cone_info); 
            }

            count++;
        }
    }

    

    void set_ROI(vector<pcl::PointCloud<PointType>::Ptr> input_cloud_vec ){
        for (auto iter = input_cloud_vec.begin(); iter != input_cloud_vec.end(); ++iter){

            PointType maxPoint,minPoint;
            pcl::getMinMax3D(*(*iter), minPoint, maxPoint);

            float tolerance = 4*cal_range(minPoint)*tan(40/32*PI/180);
            clustering((*iter),ObjCandidateCloud[1], tolerance , 10, 500);

        }
    }
    
    void clustering(pcl::PointCloud<PointType>::Ptr input_cloud, vector<pcl::PointCloud<PointType>::Ptr>& output_cloud_vec,
     double clusterTolerance, int minSize , int maxSize){
        
        int clusternum =1;
        
        std::vector<int> indice;
        pcl::removeNaNFromPointCloud(*input_cloud,*input_cloud,indice);
        pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);
        
        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(input_cloud);  // 입력 클라우드 설정
        sor.setLeafSize(.2f, .2f, .05f);  // Voxel 크기 설정 (x, y, z)
        //다운샘플링을 수행
        sor.filter(*downsampled_cloud);

        if (downsampled_cloud->points.size() > 0){
            pcl::search::KdTree<pcl::PointXYZI>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZI>);
            tree->setInputCloud(downsampled_cloud);
            std::vector<pcl::PointIndices> clusterIndices;
            pcl::EuclideanClusterExtraction<pcl::PointXYZI> ec;
            ec.setClusterTolerance(clusterTolerance);
            ec.setMinClusterSize(minSize);
            ec.setMaxClusterSize(maxSize);
            ec.setSearchMethod(tree);
            ec.setInputCloud(downsampled_cloud);
            ec.extract(clusterIndices);

            for (std::vector<pcl::PointIndices>::const_iterator it = clusterIndices.begin (); it != clusterIndices.end (); ++it)
            {
                pcl::PointCloud<PointType>::Ptr ClusterCloud(new pcl::PointCloud<PointType>);
                for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
                {   

                    pcl::PointXYZI pt = downsampled_cloud->points[*pit];
                    if(maxSize == 800) pt.intensity = 10*clusternum;
                    ClusterCloud->points.push_back(pt);
                }
                clusternum++;

                if(maxSize == 500){
                   *Clustered_Cloud += *ClusterCloud;
                }
                output_cloud_vec.push_back(ClusterCloud);
            }       
        }
        
    }

    
    void publishCloud(){
        // 2. Publish clouds
        sensor_msgs::PointCloud2 laserCloudTemp;

        if (pubROICloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*ROICloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id ="map";
            pubROICloud.publish(laserCloudTemp);
        }

        if (pubOuter.getNumSubscribers() != 0){
            Vt.ROIzonevisualization(outer_zone, outer,inners);
            pubOuter.publish(outer_zone);
        }

        if (pubObjCenter.getNumSubscribers() != 0){
            Vt.visual_object_center(obj_center_point, obj_center_markerarray,"map");
            pubObjCenter.publish(obj_center_markerarray);
        }

        if (pubObjBoundary.getNumSubscribers() != 0){
            Vt.visual_cones_boundary(obj_center_point, obj_boundary_markerarray,"map");
            pubObjBoundary.publish(obj_boundary_markerarray);
        }
        if(pubNearestInner.getNumSubscribers() != 0){
            Vt.nearestNInnerZone_visualization(nearest_inner_zone,near_ego_inners);
            pubNearestInner.publish(nearest_inner_zone);
        }
    }
    
};

