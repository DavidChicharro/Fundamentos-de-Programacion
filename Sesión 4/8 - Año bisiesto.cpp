/*
Cree un programa que lea el número de un año e indique
si es bisiesto o no. Un año es bisiesto si es múltiplo
de cuatro, pero no de cien. Excepción a la regla anterior son
los múltiplos de cuatrocientos que siempre son bisiestos.
*/

#include <iostream>

using namespace std;

int main(){
	int anio;
	bool condicion;
	
	// Entrada de datos:
	
	cout << "Introduzca un anio ";
	cin >> anio;
	
	//Cómputos:
	
	condicion = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
	
	// Salida de resultados:
	
	if (condicion)
		cout << "\nEl anio es bisiesto \n\n";
	else 
		cout << "\nEl anio no es bisiesto \n\n";
		
	system ("pause");
}
