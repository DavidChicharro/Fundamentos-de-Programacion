/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 1: Errores en funciones
Encuentre los errores en las siguientes funciones
*/

#include <iostream>

using namespace std;


int ValorAbsoluto (int entero) {
	if (entero < 0)
		entero = -entero;				// Falta: return entero
	else									// No sería necesario el else
		return entero;
}

void Cuadrado (int entero ) {		// La función void no devuelve nada
	return entero*entero;
}

void Imprime(double valor) {
	double valor;						// la variable valor ya está previamente declarada
	cout << valor;
}

bool EsPositivo(int valor) {
	if (valor > 0)
		return true;					// hay que declarar un else para los casos en los que el número sea negativo
}
