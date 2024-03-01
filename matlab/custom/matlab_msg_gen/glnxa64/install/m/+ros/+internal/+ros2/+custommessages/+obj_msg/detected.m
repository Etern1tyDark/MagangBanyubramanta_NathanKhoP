function [data, info] = detected
%Detected gives an empty data for obj_msg/Detected
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'obj_msg/Detected';
[data.color, info.color] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.x, info.x] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.y, info.y] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.angle, info.angle] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.RED, info.RED] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 2, [NaN]);
[data.YELLOW, info.YELLOW] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 3, [NaN]);
[data.BLUE, info.BLUE] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 4, [NaN]);
info.MessageType = 'obj_msg/Detected';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,7);
info.MatPath{1} = 'color';
info.MatPath{2} = 'x';
info.MatPath{3} = 'y';
info.MatPath{4} = 'angle';
info.MatPath{5} = 'RED';
info.MatPath{6} = 'YELLOW';
info.MatPath{7} = 'BLUE';
