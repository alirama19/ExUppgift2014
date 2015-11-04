function [] = receiveTest(port)
%RECEIVE Summary of this function goes here
%   Detailed explanation goes here
arduino = serial(port);
set(arduino,'BaudRate',115200);

% set(arduino,'timeout',300);
% set(arduino,'Terminator','CR/LF');

fopen(arduino);

%  N = 70;
%  y = zeros(1, N);
%  
%  for i=1:N
% 
%         y(i) = fscanf(arduino, '%i');
%     
%  %   N = N+1;
%         
%     figure(1);
%     plot(y);
%     xlabel('Tid(s)');
%     ylabel('rndNbr');
%     title('Receive-test');
%     grid on
%         
% 
%  end 

index = 1;
N = 60;
aRead = ' ';
y = zeros(1, N);

while(index <= N)
    
    if arduino.BytesAvailable > 0
        aRead = fread(arduino, 100, 'int32');
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
 
% while(index <= N)
%     
%     if arduino.BytesAvailable > 0
%         aRead = fscanf(arduino, '%i');
%         y(index) = aRead;
%        
%         index = index + 1; 
%     figure(1);
%     plot(y);
%     xlabel('Tid(s)');
%     ylabel('rndNbr');
%     title('Receive-test');
%     grid on
%     end
% 
% end
 
end

