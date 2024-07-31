import rospy
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import PointCloud2, PointField
import sensor_msgs.point_cloud2 as pc2
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from math import sqrt
import threading

# Initialize global variables to store positions
position1 = None
position2 = None
time_stamps = []
distances = []

# Callback functions for the subscribers
def callback1(msg):
    global position1
    position1 = msg.pose.position
    publish_pointcloud1()

def callback2(msg):
    global position2
    position2 = msg.pose.position
    publish_pointcloud2()

# Calculate the Euclidean distance between two positions
def calculate_distance(pos1, pos2):
    return sqrt((pos1.x - pos2.x)**2 + (pos1.y - pos2.y)**2)

# Function to publish PointCloud2 messages for the first topic
def publish_pointcloud1():
    if position1 is not None:
        points = [(position1.x, position1.y, position1.z)]
        header = rospy.Header()
        header.stamp = rospy.Time.now()
        header.frame_id = 'map'
        
        fields = [
            PointField('x', 0, PointField.FLOAT32, 1),
            PointField('y', 4, PointField.FLOAT32, 1),
            PointField('z', 8, PointField.FLOAT32, 1)
        ]
        
        point_cloud = pc2.create_cloud(header, fields, points)
        pub1.publish(point_cloud)

# Function to publish PointCloud2 messages for the second topic
def publish_pointcloud2():
    if position2 is not None:
        points = [(position2.x, position2.y, position2.z)]
        header = rospy.Header()
        header.stamp = rospy.Time.now()
        header.frame_id = 'map'
        
        fields = [
            PointField('x', 0, PointField.FLOAT32, 1),
            PointField('y', 4, PointField.FLOAT32, 1),
            PointField('z', 8, PointField.FLOAT32, 1)
        ]
        
        point_cloud = pc2.create_cloud(header, fields, points)
        pub2.publish(point_cloud)

# ROS Node initialization
rospy.init_node('distance_calculator', anonymous=True)
rospy.Subscriber('/local_msgs_for_vision2', PoseStamped, callback1)
rospy.Subscriber('/local_msgs_for_vision_gt', PoseStamped, callback2)
pub1 = rospy.Publisher('/point_cloud_est', PointCloud2, queue_size=10)
pub2 = rospy.Publisher('/point_cloud_gt', PointCloud2, queue_size=10)

# Initialize plot
fig, ax = plt.subplots()
line, = ax.plot([], [], 'r-')
ax.set_xlim(0, 100)  # Adjust as needed
ax.set_ylim(0, 5)   # Adjust as needed
ax.set_xlabel('Time (s)')
ax.set_ylabel('Distance')

# Animation update function
def update(frame):
    if position1 is not None and position2 is not None:
        distance = calculate_distance(position1, position2)
        current_time = rospy.get_time()
        time_stamps.append(current_time)
        distances.append(distance)
        print(distance)

        # Update the line data
        line.set_data(time_stamps, distances)
        
        # Adjust x-axis limit to follow the latest data
        if len(time_stamps) > 100:
            ax.set_xlim(time_stamps[-100], time_stamps[-1])

    return line,

# Set up animation
ani = animation.FuncAnimation(fig, update, interval=1000)  # Update every 1000ms (1 second)

# ROS spin in a separate thread
ros_thread = threading.Thread(target=rospy.spin)
ros_thread.start()

# Show plot
plt.show()

# Cleanup after closing the plot
ros_thread.join()
