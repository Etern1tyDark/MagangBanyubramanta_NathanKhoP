function ros2msg = interfaces_msg_Motion_1To2_Converter(message,ros2msg)
%interfaces_msg_Motion_1To2_Converter passes data of ROS message to ROS 2 message.
% Copyright 2019 The MathWorks, Inc.
ros2msg.x_cmd = message.XCmd;
ros2msg.y_cmd = message.YCmd;
ros2msg.yaw = message.Yaw;
ros2msg.depth = message.Depth;
end