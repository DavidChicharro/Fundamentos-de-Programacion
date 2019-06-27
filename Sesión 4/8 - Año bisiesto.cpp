/*
Cree un programa que lea el n�mero de un a�o e indique
si es bisiesto o no. Un a�o es bisiesto si es m�ltiplo
de cuatro, pero no de cien. Excepci�n a la regla anterior son
los m�ltiplos de cuatrocientos que siempre son bisiestos.
*/

#include <iostream>

using namespace std;

int main(){
	int anio;
	bool condicion;
	
	// Entrada de datos:
	
	cout << "Introduzca un anio ";
	cin >> anio;
	
	//C�mputos:
	
	condicion = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
	
	// Salida de resultados:
	
	if (condicion)
		cout << "\nEl anio es bisiesto \n\n";
	else 
		cout << "\nEl anio no es bisiesto \n\n";
		
	system ("pause");
}
