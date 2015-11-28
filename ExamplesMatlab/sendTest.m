function [] = sendTest(port)
%SENDTEST Summary of this function goes here
%   Detailed explanation goes here
arduino = serial(port);
set(arduino,'BaudRate',115200);
fopen(arduino);

A = 5;

% fprintf(arduino, A);
fwrite(arduino, A, 'char');

fclose(instrfind);
delete(instrfind);
clear instrfind

end

