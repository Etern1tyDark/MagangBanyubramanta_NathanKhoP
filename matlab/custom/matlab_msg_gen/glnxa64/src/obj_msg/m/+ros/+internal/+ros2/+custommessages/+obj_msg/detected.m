function [data, info] = detected
%Detected gives an empty data for obj_msg/Detected
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'obj_msg/Detected';
[data.GATE, info.GATE] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0, 1, [NaN]);
[data.RED, info.RED] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0, 2, [NaN]);
[data.YELLOW, info.YELLOW] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0, 3, [NaN]);
[data.BLUE, info.BLUE] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0, 4, [NaN]);
[data.type, info.type] = ros.internal.ros2.messages.ros2.default_type('uint8',1,0);
[data.x, info.x] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.y, info.y] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
info.MessageType = 'obj_msg/Detected';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,7);
info.MatPath{1} = 'GATE';
info.MatPath{2} = 'RED';
info.MatPath{3} = 'YELLOW';
info.MatPath{4} = 'BLUE';
info.MatPath{5} = 'type';
info.MatPath{6} = 'x';
info.MatPath{7} = 'y';
