function [data, info] = detected
%Detected gives an empty data for interfaces/Detected
% Copyright 2019-2021 The MathWorks, Inc.
data = struct();
data.MessageType = 'interfaces/Detected';
[data.RED, info.RED] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 0, [NaN]);
[data.YELLOW, info.YELLOW] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 1, [NaN]);
[data.BLUE, info.BLUE] = ros.internal.ros2.messages.ros2.default_type('int32',1,0, 2, [NaN]);
[data.color, info.color] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.x, info.x] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.y, info.y] = ros.internal.ros2.messages.ros2.default_type('int32',1,0);
[data.angle, info.angle] = ros.internal.ros2.messages.ros2.default_type('single',1,0);
info.MessageType = 'interfaces/Detected';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,7);
info.MatPath{1} = 'RED';
info.MatPath{2} = 'YELLOW';
info.MatPath{3} = 'BLUE';
info.MatPath{4} = 'color';
info.MatPath{5} = 'x';
info.MatPath{6} = 'y';
info.MatPath{7} = 'angle';
