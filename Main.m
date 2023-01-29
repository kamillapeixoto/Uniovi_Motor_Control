%% IMPLEMENTACION DE SISTEMAS DE CONTROLE   
% Trabajo 2
% Kamilla Peixoto 22/01/2023

clc 
clear all
close all

global diametro masa rozamiento reduccion bateria Ts;

%% Parte 1
% Define los parametros del sistema
parametros_sis();

%parametros = xmlread("params_xml.xml") %ERROR: The markup in the document following the root element must be well-formed.

% Leer los datos de velocidad
velocidad = importdata("v1.txt");

%Tiempo total en segundos
Ttot = 0:Ts:(Ts*(length(velocidad)-1));


%% a. Fuerza de empuje de la rueda (N)

% Define la funcion de transferencia
FuerzaToVel = tf([1],[masa rozamiento]); 

% Calcula la transformada de Fourrier para saber donde poner el polo
%         vel_dft = fft(velocidad);
%         vel_dft_abs = abs(vel_dft);
%         vel_dft_freq = (0:length(vel_dft)-1)*100/length(vel_dft); 
%         plot(vel_dft_freq, vel_dft_abs);
        
% Calcula la funcion de transferencia necesaria para calcular fuerza,
% para eso, se calcula la inversa y añade un filtro para que sea posible 
% derivar sin perder las informaciones del señal
pol_filt = 0.8;
vel_filt = tf(pol_filt, [1 pol_filt]);
VelToFuerza = vel_filt*inv(FuerzaToVel); 

%Filtra y Discretiza
fuerza_filt = 1;
VelToFuerza_filt_d = c2d(tf(fuerza_filt,[ 1 fuerza_filt])*VelToFuerza, Ts);

% Aplica la entrada de velocidad en la funcion de transferencia
% discretizada y filtrada
fuerza = lsim(VelToFuerza_filt_d, velocidad, Ttot);


%Verifica si la metodologia está correcta comparando las velocidades
        % velocidad_sim = lsim(c2d(FuerzaToVel, Ts), fuerza, Ttot);
        % figure()
        % plot(velocidad);
        % hold on
        % plot(velocidad_sim);
%Obs:Hay un pequeño retraso, que es esperado como resultado del filtro,
%pero no hay pérdidas significativas de información.

%% b. Velocidad de giro del motor (rpm)

%Original
velocidad_rpm = 60*velocidad/(pi*diametro*reduccion);

%Filtrada
velocidad_rpm_filt = lsim(c2d(vel_filt, Ts), velocidad_rpm, Ttot);


%% c. Velocidad lineal del vehículo (km/h)

%Original
velocidad_kmh = 3.6*velocidad;

%Filtrada
velocidad_kmh_filt = lsim(c2d(vel_filt, Ts), velocidad_kmh, Ttot);


%% d. Desplazamiento del vehículo (m)

desplazamiento = cumtrapz(velocidad); % "Integra" la velocidad

%% e. Potencia consumida por el motor (W)
    % No tiene sentido plotar los valores que no están filtrados, pues hay
    % perdidas significativas de informacion, pero se puede filtrar más
par = fuerza*reduccion; 
potencia = par.*velocidad;


%% f. Corriente suministrada por la batería (A)

corriente = potencia./bateria;


%% Representación Gráfica
menu_opt = ["a. Fuerza de empuje de la rueda (N)",
"b. Velocidad de giro del motor (rpm)"
"c. Velocidad lineal del vehículo (km/h)"
"d. Desplazamiento del vehículo (m)"
"e. Potencia consumida por el motor (W)"
"f. Corriente suministrada por la batería (A)"
"Cerrar"
];


menu_on = 1;
plotar = velocidad;
ytitle = "";
plotar2 = [];

while (menu_on)
  choice = menu("Elige el señal deseado", menu_opt);
    switch choice
        case 1
            plotar = fuerza;
            ytitle = "Fuerza (N)";
        case 2
            plotar = velocidad_rpm;
            ytitle = "Velocidad (rpm)";
            plotar2= velocidad_rpm_filt;

       case 3
            plotar = velocidad_kmh;
            ytitle = "Velocidad (km/h)";
            plotar2= velocidad_kmh_filt;
       case 4
            plotar = desplazamiento;
            ytitle = "Desplazamiento (m)";
       case 5
            plotar = potencia;
            ytitle = "Potência (W)";   
       case 6
            plotar = corriente;
            ytitle = "Corriente (A)";
        case 7
            menu_on = 0;

    end

    figure()
    plot(Ttot, plotar);
    xlabel("Tiempo (s)")
    ylabel(ytitle);

    if (length(plotar2)>0)
        hold on
        plot(Ttot, plotar2);
        legend('Original', 'Filtrado');
        plotar2 = [];
    end


end

close all

%% Parte 3 - Simulink

% Entrada: Velocidad
% Salida: Par

% Funcion de transferencia discretizada
VelToFuerzaD = c2d(VelToFuerza, Ts);

%% Mejoras

% 1) Obtener la FFT de la señal muestreada; identificando los armónicos del ruido
N = length(velocidad);
vel_fft_tot = fft(velocidad);

% Rechaza la mitad superior
vel_fft = vel_fft_tot(1:N/2+1);

% Normaliza la magnitude
vel_fft_nor = vel_fft/(N/2);

%Normaliza el primero que se queda duplicado
vel_fft_nor(1) = vel_fft_nor(1)/2;

% Calcula la magnitude
vel_fft_nor_abs = abs(vel_fft_nor);

% Define vector de frecuencias
vecfrec2 = (0:1:N-1)/(N*Ts);
vecfrec = vecfrec2(1:N/2+1);

figure()
subplot(211);
plot(vecfrec,vel_fft_nor_abs, 'LineWidth',1);
grid on
axis([-1 vecfrec(end) vel_fft_nor_abs(end)-0.1 vel_fft_nor_abs(1)+1]);
title('FFT de la señal de velocidad muestrada');
ylabel('Magnitud lineal');
xlabel('Frecuencia (kHz, lineal)');

subplot(212);
loglog(vecfrec,vel_fft_nor_abs, 'LineWidth',1);
grid on
axis([-1 vecfrec(end) 1e-4 10]);
ylabel('Magnitud log.');
xlabel('Frecuencia (Hz, log)');

% Conclusiones: ruido con frecuencias = [13 23 30.98] Khz
ruido_frec = [13 23 30.98];

%% 2) Diseñar e implementar en Matlab un filtro paso bajo para eliminar dicho ruido, eligiendo una de estas dos opciones (solo una!). Es necesario explicar brevemente el criterio elegido para seleccionar la frecuencia de corte del filtro, y comentar el resultado de aplicar el filtro.
    % a. Filtro de primero orden (0.5 puntos)
        % Ya fue implementado en la parte 1

    % b. Filtro de Butterworth de segundo orden (1 punto)

n = 2; %Filtro de segundo orden
fc   =ruido_frec(1)/2; % Frecuencia de corte
Wn = fc/vecfrec(end);  % Normaliza
[b,a] = butter(n,Wn);
vel_butter = lsim(tf(b, a, Ts), velocidad, Ttot);

%% 3) Implementar dicho filtro en Matlab. Representar tanto en el tiempo como 
% en frecuencia (FFT) las señales sin filtrar y las filtradas

%Compara respuesta en el tiempo
figure()
subplot(211);
plot(Ttot, velocidad)
hold on
plot(Ttot, vel_butter)
legend ('Original', "Filtrada")
title('FFT de la señal de velocidad muestrada');
ylabel('Velocidad lineal');

%Compara respuesta en frecuencia

subplot(212);
plot(vecfrec,vel_fft_nor_abs, 'LineWidth',1.5);
grid on
axis([-1 vecfrec(end) vel_fft_nor_abs(end)-0.1 vel_fft_nor_abs(1)+1]);
hold on


vel_fft_tot_but = fft(vel_butter);

% Rechaza la mitad superior
vel_fft_but = vel_fft_tot_but(1:N/2+1);

% Normaliza la magnitude
vel_fft_nor_but = vel_fft_but/(N/2);

%Normaliza el primero que se queda duplicado
vel_fft_nor_but(1) = vel_fft_nor_but(1)/2;

% Calcula la magnitude
vel_fft_nor_abs_but = abs(vel_fft_nor_but);

% Define vector de frecuencias
vecfrec2_but = (0:1:N-1)/(N*Ts);
vecfrec_but = vecfrec2_but(1:N/2+1);

hold on
plot(vecfrec_but,vel_fft_nor_abs_but, '--', 'LineWidth',1.5);
legend ('Original', "Filtrada")
ylabel('Magnitud lineal');
xlabel('Frecuencia (kHz, lineal)');

