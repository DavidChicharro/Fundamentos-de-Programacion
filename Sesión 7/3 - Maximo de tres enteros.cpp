/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 3: M�ximo de tres enteros
Programa que calcula el m�ximo entre 3 enteros.
El programa lee los enteros y tras calcular el 
mayor de ellos lo imprime en pantalla
*/

#include <iostream>

using namespace std;

int Max (int a, int b){
	int max;
	
	/* Se calcula el m�ximo
		entre a y b			*/
	
	if (a > b)
		max = a;
	else
		max = b;
		
	return max;
}	

int Max3 (int a, int b, int c){
	int max;
	
	// Se calcula el m�ximo entre tres entros
	
	max = Max(a, b);
			
	if (c > max)				// Si el tercer numero es mayor que a y b, c ser� el m�ximo
		max = c;
		
	return max;	
}

int main(){
	// Declaraci�n de variables
	
	int primero, segundo, tercero, maximo;
	
	cout << "Programa que calcula el maximo de tres valores enteros \n\n";
	
	// Entrada de datos
	
	cout << "Introduzca el primer entero: ";
	cin >> primero;
	cout << "Introduzca el segundo entero: ";
	cin >> segundo;
	cout << "Introduzca el tercer entero: ";
	cin >> tercero;
	
	// C�mputos
	
	maximo = Max3 (primero, segundo, tercero);
	
	// Salida de resultados
	
	cout << "\nEl maximo de los tres enteros es: " << maximo << "\n\n";
	
	system ("pause");
}
