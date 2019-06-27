/*
Programa que declara las variables x, y, z y lee su
valor desde teclado e intercambia entre sí sus valores
de forma que el valor de x pasa a y, el de y pasa a z
y el valor de z pasa a x.
*/

#include <iostream>

using namespace std;

int main(){
	int variable_x, variable_y, variable_z;					// Estas son las variables x, y, z
	int auxiliar;														// Esta es la variable auxiliar que permite el intercambio
	
	cout << "Introduzca el valor de la variable x: ";
	cin >> variable_x;
	cout << "Introduzca el valor de la variable y: ";
	cin >> variable_y;
	cout << "Introduzca el valor de la variable z: ";
	cin >> variable_z;
	
	auxiliar = variable_y;
	variable_y = variable_x;
	variable_x = variable_z;
	variable_z = auxiliar;
	
	cout << "\n\nEl valor de x es: " << variable_x << "\n";
	cout << "El valor de y es: " << variable_y << "\n";
	cout << "El valor de z es: " << variable_z << "\n\n";
	
	system ("pause");	
}
