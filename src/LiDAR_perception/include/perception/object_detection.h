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
    
    ros::Publisher pubConeCloud; // 도로에 해당하는 point cloud 중 차량의 최소회전 반경을  고려한 point cloud
    ros::Publisher pubConesCenter;
    ros::Publisher pubConesBoundary;
    ros::Publisher pubROICloud;
    ros::Publisher pubVector;
    ros::Publisher pub_prev_cone;
    ros::Publisher pubConesCenterKF;
    ros::Publisher pub_local;

    pcl::PointCloud<PointType>::Ptr groundCloudIn;// patchwork++에 의해 들어온 ground cloud를 저장
    pcl::PointCloud<PointType>::Ptr nongroundCloudIn;// patchwork++에 의해 들어온  non ground cloud를 저장

    vector<pcl::PointCloud<PointType>::Ptr> ConeCandidateCloud[2];// 콘 후보군 cloud
    pcl::PointCloud<PointType>::Ptr ConeCloud;// 콘에 해당하는 cloud
    pcl::PointCloud<PointType>::Ptr prev_ConeCloud;// 콘에 해당하는 cloud
    FixedSizeQueue<pcl::PointCloud<PointType>::Ptr>prev_ConeCloud_que;// 콘에 해당하는 cloud
    pcl::PointCloud<PointType>::Ptr Clustered_Cloud;// 클러스터링된 cloud
    pcl::PointCloud<PointType>::Ptr ROICloud;// 클러스터링된 cloud중 z값이 0 이하인 점들만 남김

    visualization_msgs::MarkerArray cone_boundary_markerarray;    
    visualization_msgs::MarkerArray cone_center_markerarray;    
    visualization_msgs::MarkerArray cone_center_markerarrayKF;    
    visualization_msgs::MarkerArray normal_vectors;    
    vector<Object_info> obj_center_point;
    vector<PointType> lastest_cones;

    std_msgs::Header cloudHeader;
    pcl::KdTreeFLANN<PointType> Ground_kdtree;
    
    tf::StampedTransform MappedTrans;
    tf::TransformBroadcaster tfBroadcaster;

    tf::StampedTransform map_2_camera_init_Trans;
    tf::TransformBroadcaster tfBroadcasterMap2CameraInit;

    tf::StampedTransform camera_2_base_link_Trans;
    tf::TransformBroadcaster tfBroadcasterCamera2Baselink;

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

        pubConeCloud = nh.advertise<sensor_msgs::PointCloud2> ("/cone_cloud", 1);
        pubROICloud = nh.advertise<sensor_msgs::PointCloud2> ("/ROI_cloud", 1); 

        pubConesCenter = nh.advertise<visualization_msgs::MarkerArray>("/cone_center_markers", 1);
        pubConesCenterKF = nh.advertise<visualization_msgs::MarkerArray>("/cone_center_markers_kf", 1);
        pubConesBoundary = nh.advertise<visualization_msgs::MarkerArray>("/cone_BoundingBox", 1);
        pubVector =  nh.advertise<visualization_msgs::MarkerArray>("/vectors", 1);
        pub_local =  nh.advertise<geometry_msgs::PoseStamped>("/local_msgs_for_vision_sub", 1);

        pub_prev_cone = nh.advertise<sensor_msgs::PointCloud2> ("/prev_conecloud", 1); 

        allocateMemory();
        resetParameters();
    }

    void allocateMemory(){

        groundCloudIn.reset(new pcl::PointCloud<PointType>());
        nongroundCloudIn.reset(new pcl::PointCloud<PointType>());
        ConeCloud.reset(new pcl::PointCloud<PointType>());
        prev_ConeCloud.reset(new pcl::PointCloud<PointType>());
        Clustered_Cloud.reset(new pcl::PointCloud<PointType>());
        ROICloud.reset(new pcl::PointCloud<PointType>());
        
        pred_position.resize(1000, Eigen::VectorXd::Zero(4));
        measurement_pack_list.resize(1000);
        meas_package.raw_measurements_ = VectorXd(2);
        EKFs.resize(1000);

        lastest_cones.resize(10000);

        cone_boundary_markerarray.markers.clear();
        cone_center_markerarray.markers.clear();
        cone_center_markerarrayKF.markers.clear();
        normal_vectors.markers.clear();

        outer = RCA.readOuterPolygon();
        inners = RCA.readInnerPolygon();
    }

    void resetParameters(){
        groundCloudIn->clear();
        nongroundCloudIn->clear();
        
        for(int i=0; i<2; i++)
            ConeCandidateCloud[i].clear();

        ROICloud->clear();
        ConeCloud->clear();
        prev_ConeCloud->clear();

        id_list.clear();
        obj_center_point.clear();
        Clustered_Cloud->clear();
        
        cone_center_markerarray.markers.clear();
        cone_center_markerarrayKF.markers.clear();
        cone_boundary_markerarray.markers.clear();
        normal_vectors.markers.clear();
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
        geometry_msgs::PoseStamped data2;
        data2  = *localMsg;
        data2.pose.position.z = 0.0;
        data2.header.frame_id = "map";

        ego_info.curr.x = localMsg->pose.position.x;

        ego_info.curr.y = localMsg->pose.position.y;

        ego_info.roll = localMsg->pose.orientation.x;

        ego_info.pitch = localMsg->pose.orientation.y;

        ego_info.yaw = localMsg->pose.orientation.z;

        data2.pose.orientation =  tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, ego_info.curr.z*PI/180);
        pub_local.publish(data2);
        
    }

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;
        cloudHeader.frame_id = "/base_link";
        cloudHeader.stamp = ros::Time::now(); 
        pcl::fromROSMsg(*laserCloudMsg, *nongroundCloudIn);

        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*nongroundCloudIn, *nongroundCloudIn, indices);
        
    }

    void cloudHandler(const boost::shared_ptr<const sensor_msgs::PointCloud2>& laserCloudMsg,
                    const boost::shared_ptr<const sensor_msgs::PointCloud2>& GroundlaserCloudMsg,
                    const boost::shared_ptr<const geometry_msgs::PoseStamped>& LocalMsg ){

        groundcloudHandler(GroundlaserCloudMsg);
        
        localMsgHandler(LocalMsg);

        ROS_INFO_STREAM("\033[1;32m" << "OD Working..."<< "\033[0m");
        
        auto start_time = std::chrono::high_resolution_clock::now();
        
        copyPointCloud(laserCloudMsg);

        RCA_test();
        
        clustering(nongroundCloudIn,ConeCandidateCloud[0], 1.0 , 20, 800);
        
        set_ROI(ConeCandidateCloud[0]);
        
        detect_object(ConeCandidateCloud[1]);
        
        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        cout << "process time :: " << duration.count() << " ms" << endl;

        Vt.visual_object_center(obj_center_point, cone_center_markerarray,cloudHeader.frame_id);

        Vt.visual_cones_boundary(obj_center_point, cone_boundary_markerarray,cloudHeader.frame_id);

        publishCloud();

        resetParameters();
    }

    void RCA_test(){
        size_t cloud_size = nongroundCloudIn->points.size();

        for(int i = 0; i < cloud_size; i++){
            nongroundCloudIn->points[i].x -= 0.4;//gps와의 match를 위한 필수 조건
            
            Point p = {nongroundCloudIn->points[i].x, nongroundCloudIn->points[i].y}; 
            
            if(RCA.isInside(outer, inners, p)){
                ConeCloud->push_back(nongroundCloudIn->points[i]);
            }
        }
    }

    pcl::PointCloud<PointType>::Ptr transformPointCloud(pcl::PointCloud<PointType>::Ptr cloudIn){

        pcl::PointCloud<PointType>::Ptr cloudOut(new pcl::PointCloud<PointType>());

        PointType *pointFrom;
        PointType pointTo;

        int cloudSize = cloudIn->points.size();
        cloudOut->resize(cloudSize);
        
        for (int i = 0; i < cloudSize; ++i){

            pointFrom = &cloudIn->points[i];
            float x1 = cos(ego_info.yaw) * pointFrom->x - sin(ego_info.yaw) * pointFrom->y;
            float y1 = sin(ego_info.yaw) * pointFrom->x + cos(ego_info.yaw)* pointFrom->y;
            float z1 = pointFrom->z;

            float x2 = x1;
            float y2 = cos(ego_info.roll) * y1 - sin(ego_info.roll) * z1;
            float z2 = sin(ego_info.roll) * y1 + cos(ego_info.roll)* z1;

            pointTo.x = cos(ego_info.pitch) * x2 + sin(ego_info.pitch) * z2 + ego_info.curr.x;
            pointTo.y = y2 + ego_info.curr.y;
            pointTo.z = -sin(ego_info.pitch) * x2 + cos(ego_info.pitch) * z2 + ego_info.curr.z;

            pointTo.intensity = pointFrom->intensity;

            cloudOut->points[i] = pointTo;
        }
        return cloudOut;
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
            Vt.visual_vector(c1,vector2point(cone_principle_vec,c1), 1.0, 1.0, 1.0,count,obj_center_point, normal_vectors,cloudHeader.frame_id);
            Vt.visual_vector(c1,vector2point(ground_normal,c1), 0.0, 0.0,1.0,count+100,obj_center_point,normal_vectors,cloudHeader.frame_id);

            double diff_angle = (acos(ground_normal.dot(cone_principle_vec)) /(magnitude(ground_normal)*magnitude(cone_principle_vec)))*180/PI;
            //if(diff_angle < 70){
               
                //clustered point의 최대 최소값
                PointType maxPoint,minPoint;
                pcl::getMinMax3D(*(*iter), minPoint, maxPoint);
                        
                Object_info cone_info;
                cone_info.max_point = maxPoint;
                cone_info.min_point = minPoint;
                cone_info.mid_point = c1;

                obj_center_point.push_back(cone_info); 
            //}

            count++;
        }
    }

    double cal_range(PointType point){
        return sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
    }
    double cal_diff(PointType point){
        return sqrt(point.x*point.x + point.y*point.y);
    }
    double cal_diff(PointType saved_Cone , PointType detected_Cone){
        double dx = saved_Cone.x - detected_Cone.x;
        double dy = saved_Cone.y - detected_Cone.y; 
        double dz = saved_Cone.z - detected_Cone.z;

        return sqrt(dx*dx + dy*dy + dz*dz);
    }

    double magnitude(const VectorXf& v) {
       return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }

    PointType vector2point(const VectorXf& v, PointType start_point){
        PointType tmp_point;
        tmp_point.x = v[0]+start_point.x;
        tmp_point.y = v[1]+start_point.y;
        tmp_point.z = v[2]+start_point.z;

        return tmp_point;
    } 
     
    VectorXf conduct_PCA (pcl::PointCloud<PointType>::Ptr input_cloud, int num){
        //num = 0이면 주축(분산도가 가장 큰 방향의 벡터를 의미함) , num=2이면 분산도가 가장 작은 방향의 벡터를 의미함

        //covariance matrix 생성
        Eigen::Matrix3f cov_;
        Eigen::Vector4f pc_mean_;
        VectorXf normal_;
        VectorXf singular_values_;

        pcl::computeMeanAndCovarianceMatrix(*input_cloud, cov_, pc_mean_);
        
        Eigen::JacobiSVD<Eigen::MatrixXf> svd(cov_, Eigen::DecompositionOptions::ComputeFullU);
        singular_values_ = svd.singularValues();
        
        // use the least singular vector as normal::PCA 수행
        normal_ = (svd.matrixU().col(num));
        if (normal_(2) < 0) { for(int i=0; i<3; i++) normal_(i) *= -1; }
        
        return normal_;// 법선 벡터를 추출
    }

    void set_ROI(vector<pcl::PointCloud<PointType>::Ptr> input_cloud_vec ){
        for (auto iter = input_cloud_vec.begin(); iter != input_cloud_vec.end(); ++iter){
            bool is_obj = true;

            size_t cloud_size = (*iter)->points.size();
            
            for(int i=0; i< cloud_size; i++){
                if((*iter)->points[i].z > 2.5) { // 건물을 제외하는 용도
                    is_obj = false;
                    break;
                }
            }

            if(is_obj) {
                PointType maxPoint,minPoint;
                pcl::getMinMax3D(*(*iter), minPoint, maxPoint);

                float tolerance = 4*cal_range(minPoint)*tan(40/32*PI/180);
                clustering((*iter),ConeCandidateCloud[1], tolerance , 10, 500);

            }
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

        if (pubConeCloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*ConeCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id =cloudHeader.frame_id;
            pubConeCloud.publish(laserCloudTemp);
        }

        if (pubROICloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*Clustered_Cloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = cloudHeader.frame_id;
            pubROICloud.publish(laserCloudTemp);
        }

        if (pub_prev_cone.getNumSubscribers() != 0){
            pcl::toROSMsg(*prev_ConeCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = cloudHeader.frame_id;
            pub_prev_cone.publish(laserCloudTemp);
        }

        
        pubConesCenter.publish(cone_center_markerarray);
        pubConesCenterKF.publish(cone_center_markerarrayKF);
        pubConesBoundary.publish(cone_boundary_markerarray);
        pubVector.publish(normal_vectors);
    }

    
};

