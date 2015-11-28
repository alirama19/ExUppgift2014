function [] = startPID(port, n, setpoint, Kp, Ki, Kd, sampletime)
%STARTPID Summary of this function goes here
%   Detailed explanation goes here

port = ' ';
n = ' ';
setpoint = ' ';
Kp = ' ';
Ki = ' ';
Kd = ' ';
sampletime = ' ';
aRead = ' ';

index = 1;

arduino = serial(port);
set(arduino,'BaudRate',115200);
fopen(arduino);

fwrite(arduino, setpoint, 'char');
fwrite(arduino, Kp, 'char');
fwrite(arduino, Ki, 'char');
fwrite(arduino, Kd, 'char');
fwrite(arduino, sampletime, 'char');

y = zeros(1, N);

while(index <= N)
    if arduino.BytesAvailable > 0
        aRead = fscanf(a);
        y(index) = aRead;
       
        index = index + 1; 
    figure(1);
    plot(y);
    xlabel('Tid(s)');
    ylabel('rndNbr');
    title('Receive-test');
    grid on
    end

end

fclose(instrfind);
delete(instrfind);
clear instrfind

end

