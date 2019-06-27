/*
Programa que lee un caracter de tipo numerico
y devuelve un entero con el numero introducido
*/

#include <iostream>

using namespace std;

int main(){
	const char CARACTER_DIGITO_CERO = '0';
	char caracter;
	int caracter_a_entero;
	
	cout << "Introduzca un caracter numerico ";
	cin >> caracter;
	
	caracter_a_entero = caracter - CARACTER_DIGITO_CERO;
	
	cout << "El entero correspondiente es " << caracter_a_entero << "\n\n"; 
	
	system ("pause");
}
