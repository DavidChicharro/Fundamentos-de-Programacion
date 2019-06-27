/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 1: Errores en funciones
Encuentre los errores en las siguientes funciones
*/

#include <iostream>

using namespace std;


int ValorAbsoluto (int entero) {
	if (entero < 0)
		entero = -entero;				// Falta: return entero
	else									// No ser�a necesario el else
		return entero;
}

void Cuadrado (int entero ) {		// La funci�n void no devuelve nada
	return entero*entero;
}

void Imprime(double valor) {
	double valor;						// la variable valor ya est� previamente declarada
	cout << valor;
}

bool EsPositivo(int valor) {
	if (valor > 0)
		return true;					// hay que declarar un else para los casos en los que el n�mero sea negativo
}
