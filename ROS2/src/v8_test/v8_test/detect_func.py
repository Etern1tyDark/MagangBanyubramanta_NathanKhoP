# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
import cv2 
from std_msgs.msg import String
from ultralytics import YOLO

camsrc_ = cv2.VideoCapture(0) # cap

class YoloPublisher(Node):

    def __init__(self):

        super().__init__('yolo_publisher')
        self.publisher_ = self.create_publisher(String, 'detected_obj', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.model = YOLO('models/mouse.pt')

    def timer_callback(self):
        self.ret, self.frame = camsrc_.read()
        results = self.model(self.frame)[0]
        self.annotated_frame = results.plot()

        msg = String() 
        detected_objs = results.boxes.cls # detected_objs -> list
        confidences = results.boxes.conf
        
        for (objs, conf) in zip(detected_objs, confidences):
            idx = objs.item()
            if (results.names[idx] == "mouse") and (conf > 0.3):
                msg.data = "Mouse object detected"
        
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)

        cv2.imshow('Frame', self.annotated_frame)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)

    yolo_publisher = YoloPublisher()

    rclpy.spin(yolo_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    yolo_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
