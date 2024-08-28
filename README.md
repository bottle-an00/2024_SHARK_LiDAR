# __2024_SHARK_LiDAR__ (TEAM: THE_GIGACHA)

<br>**Code for 2024 SHARK contest (LiDAR)**<br>
<table style="border: none; border-collapse: collapse;">
<table>
  <tr>
    <td style="border: none; padding-right: 10px; vertical-align: top;">
      <img src="https://github.com/user-attachments/assets/11b4eeb6-a9a3-4553-976a-b201eeed22be" width="400" height="561"></img>
    </td>
    <td style="border: none; padding-left: 10px; vertical-align: top;">
    <b>Morai Simulator 사용</b><br><br>
    <i>차량 정보</i><br><br>
    <ul>
        <li>Model : 2023_Hyundai_Ioniq5</li>
        <li>Steering Angle
            <ul>
                <li>Minimum Turning Radius (m) : 5.87</li>
                <li>Maximum Wheel Angle (deg) : 40</li>
            </ul>
        </li>
        <li>Exterior Dimensions
            <ul>
                <li>Length (m) : 4.635</li>
                <li>Width (m) : 1.892</li>
                <li>Height (m) : 2.434</li>
                <li>Wheelbase (m) : 3.000</li>
                <li>Front Overhang (m) : 0.845</li>
                <li>Rear Overhang (m) : 0.79</li>
            </ul>
        </li>
    </ul>
    <i>사용한 센서 정보 (Rate, 부착 위치(차량 후륜축 기준 [m]) {x,y,z} ):</i><br><br>
    <ul>
        <li>GPS: 30hz, {1.42, 0.0, 1.22}</li>
        <li>IMU: 50hz, {1.02, 0.0, 1.22}</li>
        <li>LiDAR (HDL 32e): 10hz, {1.02, 0.0, 1.25}</li>
    </ul>
</td>

  </tr>
</table>

## Demo Video
* __예선 연습 주행 영상__
  + 미션 내용<br>
  <img src="https://github.com/user-attachments/assets/663a3f76-47fa-498b-9c10-de281ead29cd" width="900" height="550"></img><br>
  [예선 연습 주행 영상 링크](https://youtu.be/yEcutZxK-b8)<br><br>
* __본선 연습 주행 영상__
  + 미션 내용<br>
  <img src="https://github.com/user-attachments/assets/25b9610e-d08a-40bd-908b-687ba823faad" width="900" height="550"></img><br>
  [본선 연습 주행 영상 링크](https://youtu.be/1a13bzOtN-Y)<br><br>

## How to run <br><br>
[install & build]
```commandline
git clone https://github.com/bottle-an00/2024_SHARK_LiDAR.git
cd 2024_SHARK_LiDAR
caktin_make
source devel/setup.bash

...morai 실행

roslaunch rosbridge_server rosbridge_websocket address:=127.0.0.1
```

[rviz 실행]
```commandline
roslaunch LiDAR_perception rviz.launch
```
[main 코드 실행]
```commandline
roslaunch LiDAR_perception main.launch
```
[PCD MAP 생성]
```commandline
roslaunch LiDAR_perception gpslam.launch
```

*미션 수행을 위한 main 코드의 자세한 설명은 [블로그](https://bottle-an00.tistory.com/category/%ED%94%8C%EC%A0%9D/SHARK%20%EB%8C%80%ED%9A%8C) 링크를 참고*<br><br>
## References

PATCHWORK++ : https://github.com/url-kaist/patchwork-plusplus-ros <br>
NDT_LOCALIZATION : https://github.com/AbangLZU/ndt_localizer <br>


