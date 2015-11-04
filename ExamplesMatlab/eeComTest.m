clear all
clc
 
arduino=serial('COM3','BaudRate',115200);
 
fopen(arduino);
 
x=linspace(1,100);
   
for i=1:length(x)
	y(i)=fscanf(arduino,'%d');
end
	
fclose(arduino);
disp('making plot..')
plot(x,y);