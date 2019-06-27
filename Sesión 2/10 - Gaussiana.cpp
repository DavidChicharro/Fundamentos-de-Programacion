/*
Programa que lee los coeficientes reales "mu" y "sigma" de una función
gaussiana. A continuación el programa leerá un valor de abscisa x y se
imprimirá el valor que toma la función del eje de coordenadas.
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

	exponencial = -0.5 * pow(((x - mu) / sigma), 2);				// División de la función en dos partes
	y = (1.0 / (sigma * sqrt(2 * PI))) * exp(exponencial);		// para hacerla más legible y comprensible
	
	cout << "\nEl valor que toma 'y' en funcion de 'x' es " << y << "\n\n";
	
	system ("pause");
}

/* Este programa ha sido reescrito, según señala el problema 11, utendiendo al uso de constantes. */
