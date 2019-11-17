/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 27 - Traspuesta

Programa que lee como entrada valores para una matriz y que
muestra por pantalla la traspuesta de ésta

*/

#include <iostream>
using namespace std;

int main(){
	// Declaracion de variables
	const int TAM_FILA = 50,
				 TAM_COL = 50;
	double matriz[TAM_FILA][TAM_COL];
	int util_filas = 0,
		 util_columnas = 0,
		num_filas, num_columnas;
	double numero;
	
	// Entrada de datos
	cout << "Indique el numero de filas que tendra la matriz: ";
	do{
		cin >> num_filas;
	}while(num_filas > TAM_FILA);
	
	cout << "Indique el numero de columnas que tendra la matriz: ";
	do{
		cin >> num_columnas;
	}while(num_filas > TAM_FILA);
	
	cout << "\nEntrada\n";
	for(int i = util_filas ; i < num_filas; i++){
		cout << "Fila " << i + 1 << "\n";
		for(int j = util_columnas ; j < num_columnas; j++){
			cin >> numero;
			matriz[i][j] = numero;			
		}
	}
	
	// Cómputos y salida de resultados
	cout << "\nSalida\n";
	for(int j = 0 ; j < num_columnas ; j++){
		for(int i = 0 ; i < num_filas ; i++)
			cout << matriz[i][j] << "   ";
		cout << "\n\n";
	}
			
	system ("pause");
}
