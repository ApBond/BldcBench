clc,clear,close
format long

simTime='0.3';
refSpeed=1500;

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
while (length(speed)~=5000)
    speed=[speed fread(com,1,'int32')];
    time=[time fread(com,1,'uint16')];
    fread(com,1,'uint8');
end
speedRPM=speed;
speedRPM=speed./100000000.0;
speedRPM=60./speedRPM;
speedRPM=speedRPM/18;
fclose(com);
time=(time-time(1))/100000;
for i=1:length(speedRPM)
    if(speedRPM(i)==inf)
        speedRPM(i)=0;
    end
end
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
grid on,hold on
plot(time-0.013,speedRPM)

title("Measure speed")
saveSpeed=speedRPM
% saveSpeed=speedRPM;
% save('speed1500PID.mat','saveSpeed','time');


Rs=0.792/2;
Ls=1.8/1000;
Km=0.0355;
%Ke=2.71;#
Ke=0.0095;
J=0.0000048*10;
Pole_pairs=4;
Ts=Ls/Rs;
Psi_f=Ke/Pole_pairs;
Zp=Pole_pairs;
Lsd=Ls;
Lsq=Ls;
Lsd_Ldq=0;

simOut=sim("model_2_dq.slx",'StopTime',simTime);
modelSpeed=simOut.rotorSpeed_rpm.signals.values;
modelTime=simOut.tout;
plot(modelTime,modelSpeed);