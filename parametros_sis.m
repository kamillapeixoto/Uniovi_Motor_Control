function  parametros_sis()
% Define los parametros del sistema

global diametro masa rozamiento reduccion bateria Ts rendimiento;

diametro   = 0.2;       % Diámetro rueda: 0.2 m
masa       = 25;        % Masa total:25 kg
rozamiento = 0.5;       % Coef. rozamiento: 0.5 N/(m/s)
reduccion  = 1/20;      % Relación reductora: 1:20
bateria    = 24;        % Tensión batería: 24 V
Ts         = 15e-3;     % Periodo de muestreo T=15ms
rendimiento= 1;         % No hay pérdidas (rendimiento del 100%).

end