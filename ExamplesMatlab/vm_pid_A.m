function [h1,h2,t,e,u] = vm_pid_A(a,n,dT,v,Kp,Ti,Td)
% shall be completed towards a pid-control loop for the water tank model
%
% h1: niv� (h�jd) i tank 1
% h2: niv� (h�jd) i tank 2
% t: tiden
% e: felsignal som differens mellan b�rv�rde v och vattenniv� h2
% u: styrsignal till pumpan

% a: arduino-objekt som f�s med funktionen a = arduino('COMxx')
% n: antal sampling
% dT: samplingstid i sekunder
% v: b�rv�rde f�r niv�n h2 i andra tanken
% Kp: proportionalitetsf�rst�rkning

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

%------------------------ end Arduino-mapping f�r water tanks -------------|
%--------------------------------------------------------------------------|


% prefill vectors
N = n; % antal iterationer
h1 = zeros(1, N);
h2 = zeros(1, N);
u = zeros(1,N);
e = zeros (1,N);
t = zeros(1, N);
v_line = v*ones(1,N);
v_Upper_line = 1.05*v*ones(1,N);
v_Lower_line = 0.95*v*ones(1,N);

% starta regleringen
maxPWM = 100;
ok=0; %anv�nds f�r att uppt�cka f�r korta samplingstider

% initialisera hj�lpvariabler f�r P-, I- och D- andelar
uP=0;
uI=0;
uD=0;
wk=0; %variabel f�r rekursiv summan i I-del

for i=1:N
    start = cputime;
    if ok <0
        i % sampling time too short!
        disp('samplingstiden �r f�r lite');
        return
    end
    % read level of tank 1
    h1(i)= a.analogRead(Ai1);
    % read level of tank 2
    h2(i)= a.analogRead(Ai2);
    
    t(i)= i;
    
    %control part
    e(i)= v - h2(i); % r�kna ut felet som differens mellan b�rv�rde och �rv�rde
%     if e(i) <= 0
%         u(i)=0; % vi kan inte ha negativa styrv�rden f�r pumpan
%     else

    %********************************************************************
    % P-delen
%        uP= 0; % proportional andel
       %uP= uP+ e(i)*Kp;
       uP = e(i)*Kp;

    %********************************************************************
    
    % I-delen
   
%     uI=40;
    wk = wk + e(i);
    uI = (dT/Ti)*wk; % integral andel
 
    %*******************************************************************
    % D-delen
    uD= 0; % derivat andel
    difference = 0;
    if (i==1)
        uD=0;
    else
        difference = e(i)-e(i-1);
        uD = Td*difference;
    end

%   end
    
    %********************************************************************
       
    %sammans�ttning av u som resulterande heltal!
    u(i)= round(uP+uI+uD);
%     end
%         
%     if e(i) <= 0
%         u(i)=0; % vi kan inte ha negativa styrv�rden f�r pumpan
%     elseif e(i) >= 0 % vi kan inte ha hur stora v�rden som helst
%         u(i)= maxPWM; % max-v�rdet f�r styrsignalet
%     end
    if(u(i) > maxPWM)
       u(i) = maxPWM;
    elseif(u(i) < 0)
       u(i) = 0;
    end
% %     
    % styr pumpan med nya styrv�rdet
    a.analogWrite(PWMA,u(i));
    
    %online-plot
    plot(t,h1,t,h2,t,e,t,v_line,t,v_Upper_line,t,v_Lower_line);
    xlabel('time(s)');
    ylabel('Water level');
    title('PID-Reglering');
    legend('h1','h2','Reglerfel','B�rv�rde','+5% felv�rde','-5% felv�rde');
    grid on
    elapsed=cputime-start; %r�knar �tg�ngen tid i sekunder
    ok=(dT-elapsed); % sparar tidsmarginalen i ok
    pause(ok); %pausar resterande tid
end % -for
% st�ng av pumpan
a.analogWrite(PWMA,0);
end

