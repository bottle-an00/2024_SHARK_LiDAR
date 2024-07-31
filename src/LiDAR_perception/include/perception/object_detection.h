#include "data_struction.h"
#include "fixedQueue.h"
#include "EKF/FusionEKF.h"
#include "EKF/measurement_package.h"
#include "visualization_tool/visualization_tool.h"
#include "RCA/Ray_Casting_Algorithm.h"
#include "tracking_tools/tracking_tools.h"

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
    
    ros::Publisher pubROICloud; 
    ros::Publisher pubClusteredCloud; 
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
    pcl::PointCloud<PointType>::Ptr RegisteredOBJCloud;// registered된 최종 object pointcloud

    visualization_msgs::MarkerArray obj_boundary_markerarray;    
    visualization_msgs::MarkerArray obj_center_markerarray;    
    visualization_msgs::MarkerArray normal_vectors;    
    visualization_msgs::MarkerArray outer_zone;    
    visualization_msgs::MarkerArray nearest_inner_zone;    

    vector<Object_info> detected_objects;
    vector<Object_info> object_DB;

    std_msgs::Header cloudHeader;
    pcl::KdTreeFLANN<PointType> Ground_kdtree;
    
    Ego_status ego_info;
    
    vector<FusionEKF> EKFs;
    vector<VectorXd> pred_position;
    vector<MeasurementPackage> measurement_pack_list;
    MeasurementPackage meas_package;

    vector<int> id_list;
    
    Visualization_tool Vt;
    tracking_tools Tt;
    Ray_Casting_Algorithm RCA;

    Polygon outer; 

    vector<Polygon> inners;
    vector<Polygon> near_ego_inners;

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
        pubClusteredCloud = nh.advertise<sensor_msgs::PointCloud2> ("/Clustered_cloud", 1);

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
        RegisteredOBJCloud.reset(new pcl::PointCloud<PointType>());

        Clustered_Cloud.reset(new pcl::PointCloud<PointType>());
        
        pred_position.resize(10000, Eigen::VectorXd::Zero(4));
        measurement_pack_list.resize(10000);
        meas_package.raw_measurements_ = VectorXd(2);
        EKFs.resize(10000);

        object_DB.resize(10000);

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
        RegisteredOBJCloud->clear();
        
        id_list.clear();
        detected_objects.clear();
        Clustered_Cloud->clear();
        
        obj_center_markerarray.markers.clear();
        obj_boundary_markerarray.markers.clear();
        normal_vectors.markers.clear();
        outer_zone.markers.clear();
        nearest_inner_zone.markers.clear();
        
        near_ego_inners.clear();

    }

    ~Object_Detection(){}
    
    void groundcloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
        
        pcl::fromROSMsg(*laserCloudMsg, *groundCloudIn);
        *groundCloudIn  = *transformPointCloud(groundCloudIn,ego_info);

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
        localMsgHandler(LocalMsg);

        groundcloudHandler(GroundlaserCloudMsg);

        copyPointCloud(laserCloudMsg);
        //
        auto start_time = std::chrono::high_resolution_clock::now();
        
        //get ROICloud with RCA
        near_ego_inners = RCA.get_nearest_N_inner_zone(6,inners,ego_info);

        RCA.set_ROI_RCA(nongroundCloudIn, ROICloud,outer,near_ego_inners,ego_info);
        //

        //Object Detection
        clustering(ROICloud,ObjCandidateCloud[0], 1.0 , 5, 2000);
        
        Adaptive_Clustering(ObjCandidateCloud[0]);

        detect_object(ObjCandidateCloud[1]);
        //

        //tracking
        tracking(detected_objects);
        //

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        ROS_INFO_STREAM("\033[1;32m" << "OD Working... process time:: "<<duration.count() << " ms" <<  "\033[0m");

        publishCloud();

        resetParameters();
    }
    
    void tracking(vector<Object_info>& detected_objects){
        
        Tt.process_matching(detected_objects, object_DB, id_list);

        //measurement 정보 입력 

        for(auto id : id_list){
            meas_package.raw_measurements_<< object_DB[id].mid_point.x, object_DB[id].mid_point.y;
            meas_package.timestamp_ = static_cast<long long>(cloudHeader.stamp.toNSec());
            meas_package.id = id;
            measurement_pack_list[id] = (meas_package);

            EKFs[id].ProcessMeasurement(measurement_pack_list[id]);

            pred_position[id] = EKFs[id].ekf_.x_;
            *RegisteredOBJCloud += *(object_DB[id].obj_cloud);
            cout << id <<endl;
        }
        
    }

    void detect_object(vector<pcl::PointCloud<PointType>::Ptr> input_cloud_vec){
        int count =0;
        bool is_obj = true;

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

            if(c1.z < -1.2){
                // kd-tree를 활용해 중심점의 2m 반경 내의 지면 PC를 추출
                std::vector<int> indices;
                std::vector<float> distances;
                pcl::PointCloud<PointType>::Ptr tmp_ground(new pcl::PointCloud<PointType>);


                if(Ground_kdtree.radiusSearch(c1, 4.0,indices, distances) > 0){
                    int count = 0;

                    for (size_t j = 0; j < indices.size(); ++j) {
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
                    Vt.visual_vector(c1,vector2point(cone_principle_vec,c1), 1.0, 1.0, 1.0,count,detected_objects, normal_vectors,"map");
                    Vt.visual_vector(c1,vector2point(ground_normal,c1), 0.0, 0.0,1.0,count+100,detected_objects,normal_vectors,"map");
                    pubVector.publish(normal_vectors);
                }

                double diff_angle = (acos(ground_normal.dot(cone_principle_vec)) /(magnitude(ground_normal)*magnitude(cone_principle_vec)))*180/PI;
                if (diff_angle > 75) is_obj = false;
            }

            if(is_obj){
               
                //clustered point의 최대 최소값
                PointType maxPoint,minPoint;
                pcl::getMinMax3D(*(*iter), minPoint, maxPoint);
                        
                Object_info obj_info;
                obj_info.max_point = maxPoint;
                obj_info.min_point = minPoint;
                obj_info.mid_point.x = (maxPoint.x + minPoint.x)/2;
                obj_info.mid_point.y = (maxPoint.y + minPoint.y)/2;
                obj_info.mid_point.z = (maxPoint.z + minPoint.z)/2;

                (obj_info.obj_cloud).reset(new pcl::PointCloud<PointType>());
                *(obj_info.obj_cloud) = *(*iter);

                *Clustered_Cloud += *(*iter);

                detected_objects.push_back(obj_info); 
            }

            count++;
        }
    }

    void Adaptive_Clustering(vector<pcl::PointCloud<PointType>::Ptr> input_cloud_vec ){
        for (auto iter = input_cloud_vec.begin(); iter != input_cloud_vec.end(); ++iter){

            PointType maxPoint,minPoint;
            pcl::getMinMax3D(*(*iter), minPoint, maxPoint);

            float tolerance = 2*cal_range(minPoint)*tan(40/32*PI/180);
            clustering((*iter),ObjCandidateCloud[1], tolerance , 5, 1500);

        }
    }
    
    void publishCloud(){
        // 2. Publish clouds
        sensor_msgs::PointCloud2 laserCloudTemp;

        if (pubROICloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*RegisteredOBJCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id ="map";
            pubROICloud.publish(laserCloudTemp);
        }

        if(pubClusteredCloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*Clustered_Cloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id ="map";
            pubClusteredCloud.publish(laserCloudTemp);
        }

        if (pubOuter.getNumSubscribers() != 0){
            Vt.ROIzonevisualization(outer_zone, outer,inners);
            pubOuter.publish(outer_zone);
        }

        if (pubObjCenter.getNumSubscribers() != 0){
            Vt.visual_object_center(detected_objects, obj_center_markerarray,"map");
            pubObjCenter.publish(obj_center_markerarray);
        }

        if (pubObjBoundary.getNumSubscribers() != 0){
            Vt.visual_cones_boundary(detected_objects, obj_boundary_markerarray,"map");
            pubObjBoundary.publish(obj_boundary_markerarray);
        }
        if(pubNearestInner.getNumSubscribers() != 0){
            Vt.nearestNInnerZone_visualization(nearest_inner_zone,near_ego_inners);
            pubNearestInner.publish(nearest_inner_zone);
        }
    }
    
};

