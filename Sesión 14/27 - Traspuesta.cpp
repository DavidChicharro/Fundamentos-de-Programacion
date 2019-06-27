/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 14
Ejercicio 27 - Traspuesta

Programa que lee como entrada valores para una matriz y que
muestra por pantalla la traspuesta de �sta

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
	
	// C�mputos y salida de resultados
	cout << "\nSalida\n";
	for(int j = 0 ; j < num_columnas ; j++){
		for(int i = 0 ; i < num_filas ; i++)
			cout << matriz[i][j] << "   ";
		cout << "\n\n";
	}
			
	system ("pause");
}
