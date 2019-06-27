/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 3: Máximo de tres enteros
Programa que calcula el máximo entre 3 enteros.
El programa lee los enteros y tras calcular el 
mayor de ellos lo imprime en pantalla
*/

#include <iostream>

using namespace std;

int Max (int a, int b){
	int max;
	
	/* Se calcula el máximo
		entre a y b			*/
	
	if (a > b)
		max = a;
	else
		max = b;
		
	return max;
}	

int Max3 (int a, int b, int c){
	int max;
	
	// Se calcula el máximo entre tres entros
	
	max = Max(a, b);
			
	if (c > max)				// Si el tercer numero es mayor que a y b, c será el máximo
		max = c;
		
	return max;	
}

int main(){
	// Declaración de variables
	
	int primero, segundo, tercero, maximo;
	
	cout << "Programa que calcula el maximo de tres valores enteros \n\n";
	
	// Entrada de datos
	
	cout << "Introduzca el primer entero: ";
	cin >> primero;
	cout << "Introduzca el segundo entero: ";
	cin >> segundo;
	cout << "Introduzca el tercer entero: ";
	cin >> tercero;
	
	// Cómputos
	
	maximo = Max3 (primero, segundo, tercero);
	
	// Salida de resultados
	
	cout << "\nEl maximo de los tres enteros es: " << maximo << "\n\n";
	
	system ("pause");
}
