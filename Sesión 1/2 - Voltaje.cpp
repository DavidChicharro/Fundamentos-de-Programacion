/*
Cree un programa que pida un valor de
intensidad y resistencia e imprima el voltaje
correspondiente, según la Ley de Ohm:
voltaje = intensidad * resistencia
*/

#include <iostream>

using namespace std;

int main(){
	double intensidad, resistencia, voltaje;
	
	cout << "Introduzca el valor de la intensidad ";
	cin >> intensidad;
	cout << "Introduzca el valor de la resistencia ";
	cin >> resistencia;
	
	voltaje = intensidad * resistencia;
		
	cout << "El valor del voltaje es " << voltaje << " voltios " << "\n\n";
		
	system ("pause");
}
