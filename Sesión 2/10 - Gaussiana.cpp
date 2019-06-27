/*
Programa que lee los coeficientes reales "mu" y "sigma" de una funci�n
gaussiana. A continuaci�n el programa leer� un valor de abscisa x y se
imprimir� el valor que toma la funci�n del eje de coordenadas.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double PI = 3.1416;
	double mu, sigma, x, exponencial, y;
	
	cout << "Introduzca el valor de la esperanza o media, dado por el parametro 'mu' ";
	cin >> mu;
	cout << "Introduzca el valor de la desviacion tipica, dado por el parametro 'sigma' ";
	cin >> sigma;
	cout << "Indique el valor de abscisa 'x' ";
	cin >> x;

	exponencial = -0.5 * pow(((x - mu) / sigma), 2);				// Divisi�n de la funci�n en dos partes
	y = (1.0 / (sigma * sqrt(2 * PI))) * exp(exponencial);		// para hacerla m�s legible y comprensible
	
	cout << "\nEl valor que toma 'y' en funcion de 'x' es " << y << "\n\n";
	
	system ("pause");
}

/* Este programa ha sido reescrito, seg�n se�ala el problema 11, utendiendo al uso de constantes. */
