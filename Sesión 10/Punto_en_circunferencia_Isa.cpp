/*
Comprobar si un punto pertenece a una circunferencia
	(x0 - x1)^2 + (y0 - y1)^2 <= r^2
	donde el centro es (x0,y0) y el punto (x1,y1)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	// Declaraci�n de variables
	double centro_x, centro_y, punto_x, punto_y, radio,
			 resta_abscisas, resta_ordenadas,
			 primer_miembro, segundo_miembro;
	
	cout << "Establece el centro de la circunferencia (x0,y0): \n";
	cin >> centro_x;
	cin >> centro_y;
	
	cout << "Indique un punto para comprobar si pertenece a la circunferencia (x,y): \n";
	cin >> punto_x;
	cin >> punto_y;
	
	cout << "Indique el radio de la circunferencia: ";
	cin >> radio;
	
	// C�mputos
	resta_abscisas = centro_x - punto_x;												// (x0 - x1)
	resta_ordenadas = centro_y - punto_y;												// (y0 - y1)
	primer_miembro = pow(resta_abscisas, 2) + pow(resta_ordenadas, 2);		// Para elevar al cuadrado cada t�rmino
	segundo_miembro = radio * radio;
	
	/* Otra opci�n ser�a:
	primer miembro = resta_abscisas * resta_abscisas + resta_ordenadas * resta_ordenadas;
	En este caso no har�a falta declarar la biblioteca <cmath>
	*/
	
	// Salida de resultados
	if (primer_miembro <= segundo_miembro)
		cout << "\nEl punto esta dentro de la circunferencia\n\n";
	else
		cout << "\nEl punto no esta dentro de la circunferencia\n\n";
		
	system("pause");
}
