/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 8
Ejercicio 6: Sumatoria de factoriales

Resoluci�n del ejercicio 46 y 47 utilizando funciones.
La primera versi�n, correspondiente al ejercicio 46, 
viene dada como comentario.

El programa lee un valor n�mero y calcula la 
sumatoria de los factoriales de n
n + (n * n+1) + (n * n+1 * n+2) + ...
*/

#include <iostream>

using namespace std;

/*	VERSI�N 1. Llamada a una funci�n Factorial
int Factorial(int i){
	int factorial = 1;		
	
	for (int j = 1 ; j <= i ; j++){
		factorial = factorial * j;
	}	
	return factorial;
}
*/

int SumaFactoriales(int numero){
	int suma = 0;
	int factorial = 1;
	
	/*
	for (int i = 1 ; i <= numero ; i++){
		suma = suma + Factorial(i);
	}
	*/
	
	for (int i = 1 ; i <= numero ; i++){
		factorial = i * factorial;
		suma = factorial + suma;
	}
	
	return suma;
}

int LeeIntRango(int minimo, int maximo){
	int a_leer;
	
	
	/* Precondici�n: el n�mero tiene que estar en
	un rango entre 1 y 20 */
	do{
		cout << "Introduzca un numero: ";
		cin >> a_leer;
	}while (minimo > a_leer || maximo < a_leer);
	
	return a_leer;
}

int main(){
	int numero, suma;
	const int MINIMO = 1, MAXIMO = 20;
	
	// Entrada de datos	
	numero = LeeIntRango(MINIMO, MAXIMO);
	
	// C�mputos	
	suma = SumaFactoriales(numero);
	
	// Salida de resultados	
	cout << suma << "\n\n";
	
	system ("pause");
}
