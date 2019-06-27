/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 40:
Calcule la funci�n potencia x^n, y la funci�n factorial n!
con n un valor entero y x un valor real. No pueden usarse las funciones de la biblioteca
cmath, por lo que tendr� que implementar los c�mputos con los bucles necesarios.
El factorial de un entero n se define de la forma siguiente:
0! = 1
n! = 1 � 2 � 3 � � � � n, ?n = 1

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

