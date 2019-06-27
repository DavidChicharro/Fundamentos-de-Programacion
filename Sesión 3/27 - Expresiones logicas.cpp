/*
Programa que lee las variables letra, edad, adivine y anio,
calcula el valor de las expresiones l�gicas siguientes e 
imprime el resultado. El resultado de las expresiones l�gicas
se almacenar�n en variables de tipo bool

	Escriba una expresi�n l�gica que sea verdadera si una variable
	de tipo car�cter llamada letra es una letra min�scula y falso en otro caso.
	
	Escriba una expresi�n l�gica que sea verdadera si una variable
	de tipo entero llamada edad es menor de 18 o mayor de 65.
	
	Escriba una expresi�n l�gica que sea verdadera si una variable
	de tipo entero llamada adivine est� entre 1 y 100.
	
	Escriba una expresi�n l�gica que sea verdadera si un a�o es bisiesto.
	Los a�os bisiestos son aquellos que o bien son divisibles por 4 pero
	no por 100, o bien son divisibles por 400.

Tenga en cuenta que cuando se imprime por pantalla (con cout) una expresi�n
l�gica que es true, se imprime 1. Si es false, se imprime un 0.
*/

#include <iostream>

using namespace std;

int main(){
	bool expresion1, expresion2, expresion3, expresion4;
	char letra;
	int edad, adivine, anio;
	
	cout << "Inserte una letra: ";
	cin >> letra;
	cout << "Inserte una edad: ";
	cin >> edad;
	cout << "Inserte un numero: ";
	cin >> adivine;
	cout << "Inserte un anio: ";
	cin >> anio;
	
	expresion1 = letra >= 'a' && letra <= 'z';
	expresion2 = edad < 18 || edad > 65;
	expresion3 = adivine >=1 && adivine <= 100;
	expresion4 = (anio % 4 == 0 && anio % 100 != 0 ) || (anio % 400 == 0);
	
	cout << "\n\nEl resultado sera 1 si lo que introdujo es verdadero o 0 si es falso" << "\n\n";
	cout << "Usted introdujo una letra minuscula -> " << expresion1 << "\n";
	cout << "La edad introducida es menor de 18 o mayor de 65 -> " << expresion2 << "\n";
	cout << "El numero que usted introdujo esta entre 1 y 100 -> " << expresion3 << "\n";
	cout << "El anio introducido es bisiesto -> " << expresion4 << "\n\n";
	
	system ("pause");
}
