function ros1msg = obj_msg_msg_Detected_2To1_Converter(message,ros1msg)
%obj_msg_msg_Detected_2To1_Converter passes data of ROS 2 message to ROS message.
% Copyright 2019 The MathWorks, Inc.    
ros1msg.Color = message.color;
ros1msg.X = message.x;
ros1msg.Y = message.y;
ros1msg.Angle = message.angle;
end