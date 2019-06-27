/*
Programa que lee un caracter en mayúscula y que lo
transforma a minúscula para imprimirlo en pantalla
Está hecho de forma que no se hace uso de las funciones
toupper ni tolower de la biblioteca <ctype>.
*/

#include <iostream>

using namespace std;

int main(){
	char mayuscula, minuscula;
	const int DIFERENCIA_A_MAYUSCULA = 32; 					// 32 es la diferencia en el codigo ASCII entre las mayúsculas y minúsculas de una letra
	
	cout << "Introduzca un caracter en mayuscula ";
	cin >> mayuscula;
	
	minuscula = mayuscula + DIFERENCIA_A_MAYUSCULA;
	
	cout << "\nEl caracter introducido en minuscula es: " << minuscula << "\n\n";
	
	system ("pause");
}
