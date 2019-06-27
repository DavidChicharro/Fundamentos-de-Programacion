/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 2: Factorial y potencia
Reescribir la solución del ejercicio 40 (factorial y potencia) modularizándola con funciones.
El programa lee un número n y un número x.
Calculará el factorial n y elevará el número x a n.
Finalmente imprimirá los resultados en pantalla: n! y x^n
*/

#include <iostream>

using namespace std;

// Funciones

long long Factorial (int n){
   int i;
   long long fact = 1;

   for (i = 2; i <= n; i++)
      fact = fact * i;

   return fact;
}

long long Potencia (int x, double n){
	int i;
	long long potencia = x;
      
	for (i = 1 ; i < n ; i++)
		potencia = x * potencia;
		
	return potencia;
}

int main(){
	// Declaración de variables
	
	int numero;
	double base;
	long long factorial, potencia;
	
	// Entrada de datos
	
	cout << "Programa que calcula el factorial de un numero n, y otro numero elevado a n \n";
	cout << "\nIntroduzca un numero n: ";
	cin >> numero;
	cout << "Intrdouzca la base, que sera elevada a n: ";
	cin >> base;
	
	// Cómputos
	
	factorial = Factorial(numero);
	potencia = Potencia(base, numero);
	
	// Salida de resultados
	
	cout << "\nEl factorial de n es " << factorial << endl;
	cout << "La potencia " << base << " elevado a " << numero << " es: " << potencia << "\n\n";
	
	system ("pause");
}
