/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 28 - Producto matrices

Programa que lee los datos de dos matrices de reales, n x m  y  m x k, respectivamente,
y que calcula el producto de ambas matrices, mostrando el resultado en pantalla.

*/

#include <iostream>
using namespace std;

int main(){
	const int MAX_FIL = 20,
				 MAX_COL = 20;
	double matriz_1[MAX_FIL][MAX_COL],
			 matriz_2[MAX_FIL][MAX_COL],
			 matriz_3[MAX_FIL][MAX_COL];
	int numero_filas_matriz_1, numero_columnas_matriz_1, numero_columnas_matriz_2;
	double numero;
	
	cout << "Introduce los datos de la primera matriz. " << endl <<
			  "Indique el numero de filas: ";
	cin >> numero_filas_matriz_1;
	cout << "Indique el numero de columnas: ";
	cin >> numero_columnas_matriz_1;
	
	// Entrada de datos
	for (int i = 0 ; i < numero_filas_matriz_1 ; i++){
		cout << "Fila " << i+1 << endl;
		for (int j = 0 ; j < numero_columnas_matriz_1 ; j++){
			cin >> numero;
			matriz_1[i][j] = numero;
		}
	}
	
	cout << "\n\nIntroduce los datos de la segunda matriz. " << endl <<
			  "El numero de filas sera " << numero_columnas_matriz_1 << endl <<
			  "Indique el numero de columnas: ";
	cin >> numero_columnas_matriz_2;
	
	for (int i = 0 ; i < numero_columnas_matriz_1 ; i++){
		cout << "Fila " << i+1 << endl;
		for (int j = 0 ; j < numero_columnas_matriz_2 ; j++){
			cin >> numero;
			matriz_2[i][j] = numero;
		}
	}
	
	// Cómputos
	for (int i = 0 ; i < numero_columnas_matriz_1 ; i++)
		for (int j = 0 ; j < numero_columnas_matriz_2 ; j++){
			matriz_3[i][j] = 0;
			for (int k = 0 ; k < numero_columnas_matriz_2 ; k++)
				matriz_3[i][j] = matriz_3[i][j] + matriz_1[i][k] * matriz_2[k][j];
		}
		
	// Salida de resultados
	cout << "\n Resultado de la matriz: \n";
	for (int i = 0 ; i < numero_filas_matriz_1 ; i++){
		for (int j = 0 ; j < numero_columnas_matriz_2 ; j++)
			cout << matriz_3[i][j] << "  ";
		
		cout << "\n";
	}
	
	cout << "\n\n";
	
	system ("pause");
}
