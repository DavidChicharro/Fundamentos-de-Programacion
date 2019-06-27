/*
Programa que nos pide la longitud del radio
y calcula el área del círculo y la longitud de la
circunferencia correspondientes. Finalmente, el programa
mostrará en pantalla los resultados. Recuerde que:
long. circunf = 2*pi*r 		área circ = pi*r^2
*/

#include <iostream>

using namespace std;

int main(){
	const double PI = 3.1415927;
	double radio, area, longitud_circunferencia;
	
	cout << "Inserte la longitud del radio ";
	cin >> radio;
	
	longitud_circunferencia = 2 * PI * radio;
	area = PI * radio * radio;
	
	cout << "La longitud de la circunferencia es " << longitud_circunferencia ;
	cout << "\nEl area del circulo es " << area << "\n\n";	
	
	system ("pause");
}

/* Este programa ha sido reescrito, según señala el problema 11, utendiendo al uso de constantes. */
