/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 40:
Calcule la función potencia x^n, y la función factorial n!
con n un valor entero y x un valor real. No pueden usarse las funciones de la biblioteca
cmath, por lo que tendrá que implementar los cómputos con los bucles necesarios.
El factorial de un entero n se define de la forma siguiente:
0! = 1
n! = 1 × 2 × 3 × · · · n, ?n = 1

*/

#include <iostream>

using namespace std;

int main(){
	int n, i, fact;
	double x, potencia;
	
	cout << "Programa para calcular el factorial de n (n!) y x^n ";
	cout << "\nIntroduzca n: ";
	cin >> n;
	cout << "\nIntroduzca x: ";
	cin >> x;
	
	fact = 1;
	
	for (i = 2; i <= n; i++)
      fact = fact * i;
      
   potencia = x;
      
	for (i = 1 ; i < n ; i++)
		potencia = x * potencia;
      
	cout << "El factorial de " << n << " es: " << fact << "\n\n";
	cout << "La potencia " << x << " elevado a " << n << " es: " << potencia << "\n\n";
	
	system ("pause");
}

