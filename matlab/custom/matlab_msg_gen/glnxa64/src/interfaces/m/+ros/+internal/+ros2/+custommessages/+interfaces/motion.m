function [data, info] = motion
%Motion gives an empty data for interfaces/Motion
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'interfaces/Motion';
[data.x_cmd, info.x_cmd] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.y_cmd, info.y_cmd] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.yaw, info.yaw] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.depth, info.depth] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
info.MessageType = 'interfaces/Motion';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'x_cmd';
info.MatPath{2} = 'y_cmd';
info.MatPath{3} = 'yaw';
info.MatPath{4} = 'depth';
