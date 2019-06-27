/*
Programa que lee tres enteros desde teclado y nos dice si están ordenados
(da igual si es de forma ascendente o descendente) o no lo están.
*/

#include <iostream>

using namespace std;

int main(){
	int numero1, numero2, numero3;
	bool condicion1, condicion2;
	
	// Entrada de datos:
	
	cout << "Introduzca el primer numero: ";
	cin >> numero1;
	cout << "Introduzca el segundo numero: ";
	cin >> numero2;
	cout << "Introduzca el tercer numero: ";
	cin >> numero3;
	
	// Cómputos:
	
	condicion1 = numero1 > numero2 && numero2 > numero3;
	condicion2 = numero3 > numero2 && numero2 > numero1;
	
	// Salida de resultados:
	
	if (condicion1 || condicion2)
		cout << "\nLos numeros estan ordenados \n\n";
	else
		cout << "\nLos numeros no estan ordenados \n\n";
		
	system ("pause");
}
