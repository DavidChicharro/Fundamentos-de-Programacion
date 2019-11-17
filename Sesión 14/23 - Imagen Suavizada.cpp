/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 23 - Imagen Suavizada

Programa que lee el tamaño de una imagen (filas y columnas) y los datos correspondientes. 
El programa construirá la imagen suavizada e imprimirá el resultado en pantalla.

*/


#include <iostream>
using namespace std;

class ImagenBlancoNegro{
private:
	static const int MAX_FIL = 100,
						  MAX_COL = 100;
	int matriz_privada[MAX_FIL][MAX_COL];
	int util_filas;
	int util_columnas;
	
public:
	ImagenBlancoNegro (int filas_utilizadas, int columnas_utilizadas)
		:util_filas(filas_utilizadas), util_columnas(columnas_utilizadas)
	{
	}
	
	int TotalUtilizadosFilas(){
		return util_filas;
	}
	
	int TotalUtilizadosColumnas(){
		return util_columnas;
	}
	
	int Pixel(int fila, int columna){
		return matriz_privada[fila][columna];
	}

	void Modifica (int fila, int columna, int nuevo){
		matriz_privada[fila][columna] = nuevo;
	}
	
	void Aniade (int fila, int columna, int nuevo){
		matriz_privada[fila][columna] = nuevo;
	}
	
	ImagenBlancoNegro Suaviza(ImagenBlancoNegro imagen){
		int suma, util_suma, promedio;
		ImagenBlancoNegro suavizada(imagen);
		
		for (int i = 1 ; i < util_filas - 1 ; i++)
			for (int j = 1 ; j < util_columnas - 1 ; j++){				
				suma = 0;
				util_suma = 0;
				
				for (int k = i-1 ; k < i+2 ; k++)
					for (int l = j-1 ; l < j+2 ; l++)
						if (matriz_privada[k][l] >= 0){
							suma = suma + matriz_privada[k][l];
							util_suma++;
						}
				if (util_suma == 0)
					suavizada.Modifica(i, j, 0);
				else{
					promedio = suma / util_suma;
					suavizada.Modifica(i, j, promedio);
				}				
			}
			
		return suavizada;
	}
};

int main(){
	// Declaración de variables
	int num_filas, num_columnas, numero;
	
	// Entrada de datos
	cout << "Introduzca el numero de filas de la matriz: ";
	cin >> num_filas;
	cout << "Introduzca el numero de columnas de la matriz: ";
	cin >> num_columnas;
	
	ImagenBlancoNegro imagen(num_filas, num_columnas);
	
	for (int i = 0 ; i < num_filas ; i++)
		for (int j = 0 ; j < num_columnas; j++){
			cin >> numero;
			imagen.Aniade(i, j, numero);
		}
		
	// Cómputos
	ImagenBlancoNegro suavizada(imagen.Suaviza(imagen));
	
	// Salida de resultados
	cout << "\n\nMatriz original: " << endl;
	for (int i = 0 ; i < imagen.TotalUtilizadosFilas() ; i++){
		for (int j = 0 ; j < imagen.TotalUtilizadosColumnas() ; j++)
			cout << imagen.Pixel(i, j) << "\t";
		cout << "\n\n";
	}
	
	cout << "\n\nMatriz resultante: " << endl;
	for (int i = 0 ; i < suavizada.TotalUtilizadosFilas() ; i++){
		for (int j = 0 ; j < suavizada.TotalUtilizadosColumnas() ; j++)
			cout << suavizada.Pixel(i, j) << "\t";
		cout << "\n\n";
	}
	
	system ("pause");
}
