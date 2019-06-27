/*
Programa que lee tres enteros desde teclado y nos dice si 
están ordenados ascendentemente, descendentemente o no lo están.
Para resolver este problema, se debe usar una variable de tipo enumerado.
*/

#include <iostream>

using namespace std;

enum class NumerosOrdenados {ordenados_ascendente, ordenados_descendente, no_estan_ordenados};

int main(){
	int numero1, numero2, numero3;
	bool condicion1, condicion2;
	NumerosOrdenados numeros_ordenados;
	
	// Entrada de datos:
	
	cout << "Introduzca el primer numero: ";
	cin >> numero1;
	cout << "Introduzca el segundo numero: ";
	cin >> numero2;
	cout << "Introduzca el tercer numero: ";
	cin >> numero3;
	
	// Cómputos:
	
	condicion1 = numero3 > numero2 && numero2 > numero1;
	condicion2 = numero1 > numero2 && numero2 > numero3;	
		
	if (condicion1)
		numeros_ordenados = NumerosOrdenados::ordenados_ascendente;
	else if (condicion2)
		numeros_ordenados = NumerosOrdenados::ordenados_descendente;
	else
		numeros_ordenados = NumerosOrdenados::no_estan_ordenados;
		
	// Salida de resultados:
	
	if (numeros_ordenados == NumerosOrdenados::ordenados_ascendente)
		cout << "\nLos numeros estan ordenados ascendentemente " << "\n\n";
	else if (numeros_ordenados == NumerosOrdenados::ordenados_descendente)
		cout << "\nLos numeros estan ordenados descendentemente " << "\n\n";
	else
		cout << "\nLos numeros no estan ordenados " << "\n\n";
		
	system ("pause");
}
