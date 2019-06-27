/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 46: Sumatoria de un factorial, bucle anidado

Programa que lee un valor n y calcula la 
sumatoria de los factoriales de n
n + (n * n+1) + (n * n+1 * n+2) + ...
*/

#include <iostream>

using namespace std;

int main(){
	int n, i, j, factorial, suma;
	
	// Entrada de datos
	
	cout << "Introduzca un numero: ";
	cin >> n;
	
	suma =0;
	factorial = 1;
	
	// Cómputos
	
	for (i = 1 ; i <= n ; i++){		
		for (j = i ; j >= 1 ; j--){
			factorial =  j * factorial;	
		}
		suma = suma + factorial ;
		factorial = 1;
	}
	
	// Salida de resultados
	
	cout << suma << "\n\n";
	
	system ("pause");
}
