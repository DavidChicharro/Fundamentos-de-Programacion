/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 47: Sumatoria de un factorial, bucle simple

Resolución del ejercicio 46 sin utilizar bucles anidados, 
es decir, usando un único bucle:
El programa lee un valor n y calcula la 
sumatoria de los factoriales de n
n + (n * n+1) + (n * n+1 * n+2) + ...

*/

#include <iostream>

using namespace std;

int main(){
	// Declaración de variables
	
	int numero, i, factorial, suma;
	
	// Entrada de datos
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	
	// Cómputos
	
	suma = 0;
	factorial = 1;
	
	for (i = 1 ; i <= numero ; i++){
		factorial = i * factorial;
		suma = factorial + suma;
	}
	
	// Salida de resultados
	
	cout << suma << "\n\n";
	
	system ("pause");
}
