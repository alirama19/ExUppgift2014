function [] = sendTest(port)
%SENDTEST Summary of this function goes here
%   Detailed explanation goes here
arduino = serial(port, 'BaudRate', 115200,'databits', 8);
% s=serial(‘COM3’,’BaudRate’,115200,’databits’,8)
fopen(arduino);

pause(1);
fwrite(arduino, 1, 'int8');

fclose(instrfind);
delete(instrfind);
clear instrfind

end

