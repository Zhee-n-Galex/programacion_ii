clear all
clf
close all

%CARGA DE DATOS
t=load('tiemposVectorDinamicoOrdenacionRapida.txt'); %Carga en memoria el fichero


x=t(:,1); %Eje x: n, primera columna
y_bs=t(:,2); %Eje y: tiempos t(n), segunda columna



%REPRESENTACI�N GR�FICA

plot(x, y_bs, '*b'); 




title('Ordenaci�n R�pida ');
xlabel ('Longitud del vector n');
ylabel ('Tiempo (segs)');

