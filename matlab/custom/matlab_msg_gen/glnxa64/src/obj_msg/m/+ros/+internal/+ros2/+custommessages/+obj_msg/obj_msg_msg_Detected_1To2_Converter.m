function ros2msg = obj_msg_msg_Detected_1To2_Converter(message,ros2msg)
%obj_msg_msg_Detected_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.color = message.Color;
ros2msg.x = message.X;
ros2msg.y = message.Y;
ros2msg.angle = message.Angle;
end