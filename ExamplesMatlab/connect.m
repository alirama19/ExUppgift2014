function arduino = connect (port)
arduino = serial(port);
set(arduino,'timeout',300);
set(arduino,'BaudRate',115200);
set(arduino,'Terminator','CR/LF');
fopen(arduino);
end
