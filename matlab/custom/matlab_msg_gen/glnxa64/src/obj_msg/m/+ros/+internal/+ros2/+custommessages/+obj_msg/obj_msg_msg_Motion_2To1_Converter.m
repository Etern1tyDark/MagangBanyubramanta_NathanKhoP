function ros1msg = obj_msg_msg_Motion_2To1_Converter(message,ros1msg)
%obj_msg_msg_Motion_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.XCmd = message.x_cmd;
ros1msg.YCmd = message.y_cmd;
ros1msg.Yaw = message.yaw;
ros1msg.Depth = message.depth;
end