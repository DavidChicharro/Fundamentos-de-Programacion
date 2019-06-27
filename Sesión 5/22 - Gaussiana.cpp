/*
Funcion Gaussiana
Primero se definen los par�metros de la funci�n:
	esperanza o media
	desviaci�n t�pica (>= 0)
Y se definir� entre un m�nimo y un m�ximo, adem�s
de un incremento, que indicar� los saltos de los 
valores a representar a partir del m�nimo, es decir
m�n, m�n+incremento, m�n+2*incremento, ... m�x
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double PI = 3.14159265;
	double esperanza, desviacion, x, y, divisor, exponencial,
			 minimo, maximo, incremento, salto_de_incremento;
	
	cout << "Introduzca el valor de la esperanza o media ";
	cin >> esperanza;
	cout << "Introduzca el valor de la desviacion tipica ";
	
	do{
		cin >> desviacion;
	}while (desviacion < 0);
	
	cout << "Indique entre que valores se representara la funcion en el eje x \n";
	cout << "Minimo: ";
	cin >> minimo;
	cout << "Maximo: ";
	
	do{
		cin >> maximo;
	}while (maximo < minimo);
	
	cout << "Introduzca el incremento de los valores a representar: ";
	cin >> salto_de_incremento;
	
	x = minimo;
	incremento = 0;
	
	while (x <= maximo){
		exponencial = -0.5 * pow(((x - esperanza) / desviacion), 2);
		divisor = desviacion * sqrt(2 * PI);
		y = (1.0 / divisor) * exp(exponencial);
		
		cout << y << "\t";
		incremento++;
		x = minimo + incremento * salto_de_incremento;
	}
	
	cout << "\n\n";
	
	system ("pause");
}
