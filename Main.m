%% IMPLEMENTACION DE SISTEMAS DE CONTROLE   
% Trabajo 2
% Kamilla Peixoto 22/01/2023

clc 
clear all

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
FuerzaToVel = tf([1],[masa rozamiento]); % Es necesario discretizar la FT??

% Calcula la inversa y añade un polo bien distante para que sea causal
% sin que altere su comportamiento
pol_dist = 1000000;
VelToFuerza = tf(pol_dist, [1 pol_dist])*inv(FuerzaToVel); 

% aplica la entrada de velocidad
fuerza = lsim(VelToFuerza, velocidad, Ttot);


%Verifica si la metodologia está correcta comparando las velocidades

velocidad_sim = lsim(FuerzaToVel, fuerza, Ttot);
figure()
plot(velocidad);
hold on
plot(velocidad_sim);

%% b. Velocidad de giro del motor (rpm)

velocidad_rpm = 60*velocidad/(pi*diametro*reduccion);


%% c. Velocidad lineal del vehículo (km/h)

velocidad_kmh = 3.6*velocidad;


%% d. Desplazamiento del vehículo (m)

desplazamiento = cumtrapz(velocidad);

%% e. Potencia consumida por el motor (W)

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

while (menu_on)
  choice = menu("Elige el señal deseado", menu_opt);
    switch choice
        case 1
            plotar = fuerza;
            ytitle = "Fuerza (N)";
        case 2
            plotar = velocidad_rpm;
            ytitle = "Velocidad (rpm)";
       case 3
            plotar = velocidad_kmh;
            ytitle = "Velocidad (km/h)";
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
end

close all