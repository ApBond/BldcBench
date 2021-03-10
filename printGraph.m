clc,clear,close
figure
hold on
grid on
load('speed300.mat');
plot(time,saveSpeed);
load('speed500.mat');
plot(time,saveSpeed);
load('speed1000.mat');
plot(time,saveSpeed);
load('speed1500.mat');
plot(time,saveSpeed);
load('speed2000.mat');
plot(time,saveSpeed);