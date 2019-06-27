/*
Programa que calcula el inter�s dado por un
plazo fijo bancario, donde la cantidad depositada 
inicialmente viene dada por la variable 'capital'
y el inter�s por la variable 'interes'. El programa
debe calcular una variable 'total' que indique el
dinero que se tendr� al cabo de un a�o
*/

#include <iostream>

using namespace std;

int main(){
	double capital, interes, total;
	
	cout << "Introduzca la cantidad depositada en el banco a plazo fijo ";
	cin >> capital;
	cout << "Indique el interes del plazo fijo ";
	cin >> interes;
	
	total = capital + capital * interes / 100 ;
	
	cout << "El dinero obtenido al cabo de un anio es " << total << "\n\n";  

	system ("pause") ;
}


/*
En caso de sustituir la variable 'total' por
'capital', el compilador muestra un mensaje de 
advertencia, ya que se ha utilizado una variable
a la que previamente ya se le hab�a asignado un valor.
No obstante el resultado el correcto y se podr�a
sustituir, aunque no es lo m�s adecuado.
*/

