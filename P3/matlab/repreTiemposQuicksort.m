clear all
clf
close all

%CARGA DE DATOS
t=load('tiemposVectorDinamicoOrdenacionRapida.txt'); %Carga en memoria el fichero


x=t(:,1); %Eje x: n, primera columna
y_bs=t(:,2); %Eje y: tiempos t(n), segunda columna



%REPRESENTACIÓN GRÁFICA

plot(x, y_bs, '*b'); 




title('Ordenación Rápida ');
xlabel ('Longitud del vector n');
ylabel ('Tiempo (segs)');

