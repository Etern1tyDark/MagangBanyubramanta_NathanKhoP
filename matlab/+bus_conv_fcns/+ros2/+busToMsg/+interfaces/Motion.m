function rosmsgOut = Motion(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.x_cmd = int32(slBusIn.x_cmd);
    rosmsgOut.y_cmd = int32(slBusIn.y_cmd);
    rosmsgOut.yaw = int32(slBusIn.yaw);
    rosmsgOut.depth = int32(slBusIn.depth);
end
