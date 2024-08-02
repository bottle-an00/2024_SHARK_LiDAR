import rosbag
import argparse

def change_frame_id(input_bag, topic_name, new_frame_id):
    with rosbag.Bag("new_bag.bag", 'w') as outbag:
        for topic, msg, t in rosbag.Bag(input_bag).read_messages():
            if topic == topic_name:
                # 특정 토픽의 frame_id를 변경
                if hasattr(msg, 'header') and hasattr(msg.header, 'frame_id'):
                    msg.header.frame_id = new_frame_id
            outbag.write(topic, msg, t)
    print(f"frame_id of topic '{topic_name}' changed to '{new_frame_id}' in {output_bag}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Change frame_id of a specific topic in a rosbag file.')
    parser.add_argument('input_bag', help='Path to the input bag file')
    parser.add_argument('topic_name', help='Name of the topic whose frame_id needs to be changed')
    parser.add_argument('new_frame_id', help='New frame_id for the topic')

    args = parser.parse_args()

    change_frame_id(args.input_bag, args.topic_name, args.new_frame_id)
