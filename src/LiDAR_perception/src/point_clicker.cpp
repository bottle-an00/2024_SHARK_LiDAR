#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>
#include <vtkPointPicker.h>
#include <vtkCallbackCommand.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "perception/data_struction.h"

namespace fs = boost::filesystem;

pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud4nonground(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud4lane(new pcl::PointCloud<pcl::PointXYZRGB>);
int pointIndex = 0;
std::ofstream outputFile;
std::vector<std::string> lines; // 텍스트 파일의 줄을 저장할 벡터
std::string outputFilePath;

bool is_o_clicked = true;

void loadFile(const std::string& filePath)
{
    std::ifstream inputFile(filePath);
    std::string line;
    lines.clear();
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    else
    {
        std::cerr << "Unable to open file " << filePath << std::endl;
    }
}

void saveFile(const std::string& filePath)
{
    std::ofstream outputFile(filePath);
    if (outputFile.is_open())
    {
        for (const auto& line : lines)
        {
            outputFile << line << std::endl;
        }
        outputFile.close();
    }
    else
    {
        std::cerr << "Unable to open file " << filePath << std::endl;
    }
}

int countLinesInFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line))
    {
        ++lineCount;
    }

    file.close();
    return lineCount;
}

class PointPickingInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
    static PointPickingInteractorStyle* New();
    vtkTypeMacro(PointPickingInteractorStyle, vtkInteractorStyleTrackballCamera);

    void OnLeftButtonDown() override
    {
        int* clickPos = this->GetInteractor()->GetEventPosition();
        vtkSmartPointer<vtkRenderer> renderer = this->GetInteractor()->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
        vtkSmartPointer<vtkPointPicker> picker = vtkSmartPointer<vtkPointPicker>::New();
        picker->Pick(clickPos[0], clickPos[1], 0, renderer);

        double* pos = picker->GetPickPosition();

        const char* keySym = this->GetInteractor()->GetKeySym();
        
        if (keySym && std::string(keySym) == std::string("i"))
        {
            std::cout << "add: " << pointIndex;
            std::cout << " mouse clicked: " << pos[0] << " " << pos[1] << " " << pos[2] << std::endl;

            pointIndex = countLinesInFile(outputFilePath);

            // 텍스트 파일에 저장
            outputFile << pointIndex << ", " << pos[0] << ", " << pos[1] << std::endl;
            lines.push_back(std::to_string(pointIndex) + ", " + std::to_string(pos[0]) + ", " + std::to_string(pos[1]));

        }
        else if (keySym && std::string(keySym) == std::string("p"))
        {
            if (!lines.empty())
            {
                std::cout << "delete!!" << endl;
                // 가장 마지막 줄을 삭제
                lines.pop_back();
                // 텍스트 파일에 다시 저장
                outputFile.close();
                saveFile(outputFilePath);
                outputFile.open(outputFilePath, std::ios::app);
            }
        }


        vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
    }
};

vtkStandardNewMacro(PointPickingInteractorStyle);

void userSetup(int& mode)
{
    std::cout << "Enter 1 to open a specific file or 2 or 3 to create a new file in a specific folder: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기

    if (choice == 1)
    {
        std::string filePath = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Outer.txt";
        outputFilePath = filePath;
    }
    else if (choice == 2)
    {
        std::string folderPath = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Inner/";
        
        // // 폴더 내 파일 갯수 파악
        int fileCount = 0;
        for (const auto& entry : fs::directory_iterator(folderPath))
        {
            if (fs::is_regular_file(entry))
            {
                fileCount++;
            }
        }
        
        // 새 파일 이름 설정
        outputFilePath = folderPath + "/zone::" + std::to_string(fileCount)+ ".txt";

        // 새 파일을 생성하고 빈 파일로 초기화
        std::ofstream newFile(outputFilePath);
        newFile.close();
    }
    else if (choice == 3)
    {
        std::string folderPath = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Parking/";
        
        mode = 1;

        // // 폴더 내 파일 갯수 파악
        int fileCount = 0;
        for (const auto& entry : fs::directory_iterator(folderPath))
        {
            if (fs::is_regular_file(entry))
            {
                fileCount++;
            }
        }
        
        // 새 파일 이름 설정
        outputFilePath = folderPath + "/parking_zone_" + std::to_string(fileCount)+ ".txt";

        // 새 파일을 생성하고 빈 파일로 초기화
        std::ofstream newFile(outputFilePath);
        newFile.close();
    }
    else
    {
        std::cerr << "Invalid choice. Exiting." << std::endl;
        exit(1);
    }
    
    outputFile.open(outputFilePath, std::ios::app);
}


int main(int argc, char** argv)
{
    int mode =0;

    userSetup(mode);

    // PCD 파일 경로 설정
    std::string pcd_file_path = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps/filtered/filtered_Ground.pcd";
    std::string pcd_file_path2 = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps/filtered/filtered_NongroundMap.pcd";
    std::string pcd_file_path3 = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps/filtered/filtered_Lane.pcd";

    // PCD 파일 읽기
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(pcd_file_path, *cloud) == -1 || pcl::io::loadPCDFile<pcl::PointXYZRGB>(pcd_file_path2, *cloud4nonground) == -1 
    || pcl::io::loadPCDFile<pcl::PointXYZRGB>(pcd_file_path3, *cloud4lane) == -1  )
    {
        PCL_ERROR("Couldn't read file \n");
        return (-1);
    }

    for(auto& point: cloud4nonground->points){
        point.r = 255;
        point.g = 255;
        point.b = 0;
    }

    for(auto& point: cloud->points){
        point.r = 155;
        point.g = 155;
        point.b = 155;
    }

    for(auto& point: cloud4lane->points){
        point.r = 0;
        point.g = 0;
        point.b = 255;
    }
    
    // PCL 시각화 객체 생성
    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
    viewer->setBackgroundColor(0, 0, 0);
    if(mode == 0){
        viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "ground cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "ground cloud");

        viewer->addPointCloud<pcl::PointXYZRGB>(cloud4nonground, "nonground cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "nonground cloud");

        viewer->addPointCloud<pcl::PointXYZRGB>(cloud4lane, "lane cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "lane cloud");
    }else if(mode ==1){
        viewer->addPointCloud<pcl::PointXYZRGB>(cloud4lane, "lane cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "lane cloud");
    }
    viewer->addCoordinateSystem(1.0);
    viewer->initCameraParameters();
    
    // VTK 위젯 설정
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = viewer->getRenderWindow()->GetInteractor();
    vtkSmartPointer<PointPickingInteractorStyle> style = vtkSmartPointer<PointPickingInteractorStyle>::New();
    interactor->SetInteractorStyle(style);

    // 시각화 루프
    viewer->getRenderWindow()->Render();
    interactor->Start();

    // 파일 닫기
    outputFile.close();

    return 0;
}
