/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 11
Ejercicio 4: Moda

Programa que calcula la moda de un vector de caracteres.
Un vector de caracteres almacena todos los valores. A continuaci�n
se calcula la moda y por �ltimo la muestra en pantalla junto con su frecuencia.

*/

#include <iostream>
#include <cctype>
using namespace std;

/*Almacena de forma conjunta el car�cter 
y la frecuencia con la que aparece*/
struct FrecuenciaCaracter{
	char caracter;
	int frecuencia = 0;
};

/* Funcion que indica la posicion en la que se encuentra un caracter.
En caso de que no exista, devuelve una posici�n no v�lida */
int EstaCaracter(const FrecuenciaCaracter vector[], char caracter, int util){
	bool existe_caracter = false;
	int posicion;	
	
	for (int i = 0; i < util && !existe_caracter ; i++)
		if(vector[i].caracter == caracter){
			existe_caracter = true;
			posicion = i;
		}
	
	if (!existe_caracter)
		posicion = -1;		
		
	return posicion;	
}

int main(){
	// Declaraci�n de variables
	const char TERMINADOR = '#';
	const int TAMANIO = 1e5;	
	FrecuenciaCaracter vector[TAMANIO];
	char caracter;
	int util = 0;
	int posicion, maximo;
	char letra_mas_repetida;
	
	// Entrada de datos
	cin.get(caracter);
	caracter = tolower(caracter);								// Convierte en min�sculas todos los caracteres
	
	while (caracter != TERMINADOR){
		posicion = EstaCaracter(vector, caracter, util);
		
		if (posicion == -1){										// Si la posici�n es -1 (no v�lida), se le asigna una posici�n al final del vector
			vector[util].caracter = caracter;
			vector[util].frecuencia = 1;
			util++;
		}
		else
			vector[posicion].frecuencia++;					// Si el caracter existe, se aumenta la frecuencia de aparici�n
		
		cin.get(caracter);
		caracter = tolower(caracter);
	}
	
	// C�mputos
	maximo = vector[0].frecuencia;
	letra_mas_repetida = vector[0].caracter;
	
	for (int i = 1 ; i < util ; i++){						// Calcula cual es el caracter que tiene m�s apariciones
		if(maximo < vector[i].frecuencia && vector[i].caracter != ' ' ){
			maximo = vector[i].frecuencia;
			letra_mas_repetida = vector[i].caracter;
		}
	}
	
	// Salida de resultados
	cout << "La letra que mas se repite es: " << letra_mas_repetida << " y se repite " << maximo << " veces \n\n";
	
	system("pause");
}
