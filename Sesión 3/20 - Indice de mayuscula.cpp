/*
Realice un programa que lea una may�scula desde teclado sobre una variable de tipo
char. A continuaci�n, el programa imprimir� el 0 si se ha introducido el car�cter A, el 1
si era la B, el 2 si era la C y as� sucesivamente. Supondremos que el usuario introduce
siempre un car�cter may�scula.
*/

#include <iostream>

using namespace std;

int main(){
	char letra_mayuscula;
	int orden_relativo_mayuscula;
	
	cout << "Introduzca una letra mayuscula ---> ";
	cin >> letra_mayuscula;
	
	orden_relativo_mayuscula = letra_mayuscula - 'A';
	
	cout << "\nLa mayuscula " << letra_mayuscula << " esta " << orden_relativo_mayuscula << " posiciones por encima de la A \n\n";
	
	system ("pause");
}
