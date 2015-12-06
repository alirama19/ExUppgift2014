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

arduino = serial(port, 'BaudRate', 115200,'databits', 8);
fopen(arduino);

pause(1);
fwrite(arduino, setpoint, 'int8');
pause(1);
fwrite(arduino, Kp, 'int8');
pause(1);
fwrite(arduino, Ki, 'int8');
pause(1);
fwrite(arduino, Kd, 'int8');
pause(1);
fwrite(arduino, sampletime, 'int8');

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

