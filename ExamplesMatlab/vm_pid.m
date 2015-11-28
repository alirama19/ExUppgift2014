function [h1,h2,t,e,u] = vm_pid(a,n,dT,v,Kp)
% shall be completed towards a pid-control loop for the water tank model
% 
% h1: nivå (höjd) i tank 1
% h2: nivå (höjd) i tank 2
% t: tiden
% e: felsignal som differens mellan börvärde v och vattennivå h2
% u: styrsignal till pumpan

% a: arduino-objekt som fås med funktionen a = arduino('COMxx')
% n: antal sampling
% dT: samplingstid i sekunder
% v: börvärde för nivån h2 i andra tanken
% Kp: proportionalitetsförstärkning

% Arduino-mapping for watertanks, laboration 3c, febr 2014, MAH/GKS
% 
%----------------------------------------------------------------------
% Control box                                |  Arduino Uno / motor shield              |
%--------------------------------------------|---------------------------|

% outputs:
% pump-motor driven by external power source: 10V
% 
% Direction "DirA" (setting high!!= 1)       | D12                      |
% PWM-motor signal "PWMA" (0 ..255)          | D3                       |

DirA=12;PWMA=3;
a.pinMode(DirA,'output');
a.digitalWrite(DirA,1);   %-important! motorn shall never change direction!!
a.pinMode(PWMA,'output');
a.analogWrite(PWMA,0); % - starts with turned off motor, be sure to also turn off motor at the end of your programs


% analog inputs 
% water level first tank "Ai1"               | A5 (digital pin D19)       |     
% connect to Ai1-10V !!
% range of value: 0..20cm <==> 0 .. 1024

% water level second tank "Ai2"              | A2 (digital pin D16)       |
% connect to Ai2-10V !!
% range of value: 0..20cm <==> 0 .. 1024

Ai1dp=19; Ai2dp=16; Ai1=5; Ai2=2;
a.pinMode(Ai1dp,'input');
a.pinMode(Ai2dp,'input');
a.analogRead(Ai1); %-reads water level in tank 1
a.analogRead(Ai2); %-reads water level in tank 2
%------------------------ end Arduino-mapping för water tanks -------------|
%--------------------------------------------------------------------------|

ok=0; %används för att upptäcka för korta samplingstider
N = n; % antal iterationer
% prefill vectors
h1 = zeros(1, N);
h2 = zeros(1, N);
u = zeros(1,N);
e = zeros (1,N);
t = zeros(1, N);

% starta regleringen
%maxPWM = 100;
 % initialisera hjälpvariabler för P-, I- och D- andelar
 uP=0;
 uI=0;
 uD=0;
 wk=0; %variabel för rekursiv summan i I-del
 
 difference = 0;
 
  for i=1:N
    start = cputime;
    if ok <0
        i % sampling time too short!
        disp('samplingstiden är för lite');
        return
    end
    % read level of tank 1
    h1(i)= a.analogRead(Ai1);
     % read level of tank 2
    h2(i)= a.analogRead(Ai2);  
    
    t(i)= i;
    vv(i) = v;
    
    %control part
    e(i)=  v-h2(i);% räkna ut felet som differens mellan börvärde och ärvärde
    if e(i) <= 0
        u(i)=0; % vi kan inte ha negativa styrvärden för pumpan
     elseif (e(i) > 0) % vi kan inte ha hur stora värden som helst
       u(i)= 70; % max-värdet för styrsignalet
    else
        % P-delen
        %uP= 0; % proportional andel
        uP= e(i);
        
        
        % I-delen
        uI= 0; % integral andel 
        %wk = wk + e(i);
        %uI = uI + Ti*dT*wk % Använda ensam som I-regulation
        
        % D-delen
        uD= 0; % derivat andel
        
        %sammansättning av u som resulterande heltal!        
        u(i)= round(uP+uI+uD);
    end
    
    % styr pumpan med nya styrvärdet
    %if(u(i) > maxPWM)
    %    u(i) = maxPWM;
    %elseif(u(i) < 0)
    %    u(i) = 0;
    %end
    a.analogWrite(PWMA,u(i));
    
    %online-plot
    plot(t,h1,t,h2,t,u);
    elapsed=cputime-start; %räknar åtgången tid i sekunder
    ok=(dT-elapsed); % sparar tidsmarginalen i ok
    pause(ok); %pausar resterande tid
  end % -for
  % stäng av pumpan
  a.analogWrite(PWMA,0);
  % plotta en fin slutbild, lägg gärna till titel "PID" och
  % legenden för h1 och h2
  plot(t,h1,t,h2,t,e,t,u,t,vv);
  xlabel('time (s)');
  ylabel('Water level');
  title('P-reglaring');
  legend('Tank 1 level (h1)','Tank 2 level (h2)','Reglerfelet (e)', 'Styrsignalen (u)','Börvärdet (v)');
  grid on

end