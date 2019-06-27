/*
Programa que indica si un a�o es bisiesto o no lo es.
Un a�o es bisiesto si es m�ltiplo de cuatro, pero no
de cien. Como excepci�n, los m�ltiplos de cuatrocientos
siempre son bisiestos.
*/

#include <iostream>
using namespace std;

bool AnioBisiesto (int anio){
	return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int IntroduceAnio (){
	int anio;
		
	cout << "Introduzca un anio: ";
	do{
		cin >> anio;
	}while(anio < 1582);
	
	return anio;
}

int main(){
	int anio;
	bool es_bisiesto;
	
	// Entrada de datos:
	anio = IntroduceAnio();
	
	//C�mputos:	
	es_bisiesto = AnioBisiesto(anio);
	
	// Salida de resultados:	
	if (es_bisiesto)
		cout << "\nEl anio es bisiesto \n\n";
	else 
		cout << "\nEl anio no es bisiesto \n\n";
		
	system ("pause");
}
