function slBusOut = Detected(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    slBusOut.color = int32(msgIn.color);
    slBusOut.x = int32(msgIn.x);
    slBusOut.y = int32(msgIn.y);
    slBusOut.angle = int32(msgIn.angle);
end
