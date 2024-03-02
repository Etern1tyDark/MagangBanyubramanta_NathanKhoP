function slBusOut = Detected(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    slBusOut.type = uint8(msgIn.type);
    slBusOut.x = int32(msgIn.x);
    slBusOut.y = int32(msgIn.y);
end
