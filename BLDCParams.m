clc,clear

upp=[18 24];
T=[6.62/1000 5.02/1000];

ke=upp.*T./(4.*pi)

Rs=0.792/2;
Ls=1.8/1000;
Km=0.0355;
%Ke=2.71;#
Ke=0.0095;
J=0.0000048;
Pole_pairs=4;
Ts=Ls/Rs;



%Колесо
% Rs=0.19;
% Ls=0.577/1000;
% Km=0.0355;
% Ke=21.6;
% J=0.0000048;
% Pole_pairs=15;
% Ts=Ls/Rs;

Psi_f=Ke/Pole_pairs;
Zp=Pole_pairs;
Lsd=Ls;
Lsq=Ls;
Lsd_Ldq=0;