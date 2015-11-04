function [] = startPingis(N, setpoint, sampleTime, kp, ki, kd, s)

    fwrite(s, 102);
    fwrite(s, setpoint);
    fwrite(s, sampleTime);
    fprintf(s, '%s', strcat(num2str(kp), '\n'));
    fprintf(s, '%s', strcat(num2str(ki), '\n'));
    fprintf(s, '%s', strcat(num2str(kd), '\n'));
    
   switch(setpoint)
        case 35
            setpoint = 400
        case 30
            setpoint = 415
        case 25
            setpoint = 425
        case 20
            setpoint = 465
    end
sampleTime = 0.1;

controlSignal_input = '';
actualValue_input = '';

controlSignal = zeros(1, N);
actualValue = zeros(1, N);
errorValue = zeros(1,N);
sample = zeros(1,N);
fwrite(s, 100)
index = 1;


while(index <= N)
    startTime = cputime;
    
    if s.BytesAvailable > 0
        controlSignal_input = fscanf(s);
        controlSignal(index) = 10 * str2double(controlSignal_input);
        
        actualValue_input = fscanf(s);
        actualValue(index) = str2double(actualValue_input);
        
        errorValue(index) = setpoint - actualValue(index);
        
        sample(index) = index * sampleTime;
        
        plot(sample, controlSignal, 'g', sample, actualValue, 'b-', sample, errorValue, 'r--')
        
        index = index + 1; 
    end
    
    
    elapsedTime = cputime - startTime;
    
    delay = sampleTime - elapsedTime;
    
    if(delay < 0)
       disp('delay to short'); 
    end
    
    pause(delay);
end
    fwrite(s, 101)
           plot(sample, controlSignal, 'g', sample, actualValue, 'b-', sample, errorValue, 'r--', sample, setpoint, 'k:')
end



