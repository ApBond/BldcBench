clc,clear,close
com = serial('COM4','BaudRate',115200);
fopen(com);
speed=[];
torque=[];
time=[]
while 1                  
    a = fread(com,1,'uint8');                  
    if a == 11
        break;
    end
end
while (length(speed)~=1000)
    speed=[speed fread(com,1,'int32')];
    time=[time fread(com,1,'uint16')];
    fread(com,1,'uint8');
end

fclose(com);
time=(time-time(1))/100000;
% subplot(2,2,1)
% plot(time,speed(1,:))
% title("Reference speed")
% subplot(2,2,2)
% plot(time,speed(2,:))
% title("Measure speed")
% subplot(2,2,3)
% plot(time,torque(1,:))
% title("Regulator torque")
% subplot(2,2,4)
% plot(time,torque(2,:))
% title("Measure torque")
figure
grid on
plot(time,speed)
title("Measure speed")
saveSpeed=speed;
save('speed2000.mat','saveSpeed','time');