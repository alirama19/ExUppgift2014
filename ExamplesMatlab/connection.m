function[h1,h2,SP,t] = connection(a)

% t: Tid
% e: Felsignal som differens mellan börvärde(v) och vattennivån i andra behållaren(h2)
% h1: Vattennivån i övre behållaren
% h2: Vattennivån i lägre behållaren

% SP: Setpoint
% Upper_line: 5% over the setpoint
% Lower_line: 5% under the setpint.

        
 N = 700;
 h1 = zeros(1,N);
 h2 = zeros(1,N);
 e = zeros (1,N);
 t = zeros(1,N);
 SP = zeros(1,N);
 Upper_line = zeros(1,N);
 Lower_line = zeros(1,N);

 for i=1:N
    answer = fscanf (a)
    C = strsplit(answer,'S')
    number = str2double(C(1:4));
     
    h1(i)= number(1);
    h2(i) = number(2);
    SP(i) =  number(3);
    e(i)= number(4);
    Upper_line (i) = SP(i)*1.05;  
    Lower_line (i) = SP(i)*0.95;
    t(i)=i;
  
    figure(1)
    plot(t,h1,t,h2,t,SP,t,e,t,Upper_line,t,Lower_line)
    xlabel('Tid(s)');
    ylabel('Vattennivå');
    title('PID-Reglering');
    legend('h1','h2','Börvärde', 'Felvärde', '+5% felvärde','-5% felvärde');
    grid on

end 
end
