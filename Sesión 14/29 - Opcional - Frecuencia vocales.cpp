/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 14
Ejercicio [Frecuencias vocales]. (Examen Septiembre 2016) 
Queremos calcular la frecuencia absoluta de las vocales (sin acentuar) presentes en un texto 
y mostrar el resultado en forma de un diagrama de barras en el que cada barra corresponde a una vocal 
y la altura representa la frecuencia de aparici�n de la correspondiente vocal.

Un ejemplo de diagrama de barras ser�a el siguiente:
		6 		  #
		5 	 #   #
		4 	 # # #
		3 # # # # #
		2 # # # # #
		1 # # # # #
		  a e i o u
		  
Cada aparici�n de una vocal la representaremos con un asterisco *.
Defina una matriz de caracteres directamente dentro del main para almacenar las barras. 

Se emplea el car�cter '*' para indicar que la casilla est� ocupada y 
el car�cter' ' (espacio en blanco) para indicar que la casilla est� libre. 
En la matriz no almacenaremos ni los n�meros 1, 2, 3, 4, ... ni las vocales a, e, i, o , u.

Escriba un programa que lea una serie indefinida de caracteres de la entrada est�ndar (terminados en #) 
y muestre la figura (las barras, los conteos y las vocales) que representa la frecuencia absoluta de las vocales introducidas.

Por ejemplo, la anterior figura ser�a el diagrama de barras de la siguiente entrada:
	You should solve this typical exam problem in no more than 30 minutes#

*/

#include <iostream>
using namespace std;

int main(){
	const char TERMINADOR = '#';
	const int TAMANIO = 1e4;
	char vector[TAMANIO];
	int util_vector = 0;
	char caracter;
	const int FILAS = 100,
				 COLUMNAS = 5;
	char matriz[FILAS][COLUMNAS];
	int frec_a = 0, frec_e = 0, frec_i = 0, frec_o = 0, frec_u = 0;
	const char OCUPADO = '*';	
	
	// Entrada de datos
	cout << "Introduzca un texto. " << endl <<
			  "Se mostrara una grafica con la frecuencia de cada vocal. \n";
	cin.get(caracter);
	
	while(caracter != TERMINADOR){
		vector[util_vector] = caracter;
		util_vector++;
		cin.get(caracter);
	}
	
	for (int i = 0 ; i < util_vector ; i++){
		if(vector[i] == 'a' || vector[i] == 'e' || vector[i] == 'i' || vector[i] == 'o' || vector[i] == 'u'){
			if (vector[i] == 'a'){
				matriz[frec_a][0] = OCUPADO;
				frec_a++;
			}
			else if (vector[i] == 'e'){
				matriz[frec_e][1] = OCUPADO;
				frec_e++;
			}
			else if (vector[i] == 'i'){
				matriz[frec_i][2] = OCUPADO;
				frec_i++;
			}
			else if (vector[i] == 'o'){
				matriz[frec_o][3] = OCUPADO;
				frec_o++;
			}
			else if (vector[i] == 'u'){
				matriz[frec_u][4] = OCUPADO;
				frec_u++;
			}
		}	
	}
	
	int vector_frec[5] = {frec_a, frec_e, frec_i, frec_o , frec_u};
	int maximo = frec_a;
	for (int i = 1 ; i < 5 ; i++)	
		if (vector_frec[i] > maximo)
			maximo = vector_frec[i];	
	
	for (int i = 0 ; i < maximo ; i++){
		cout << "\n" << i+1 << "  ";
		for(int j = 0 ; j < 5 ; j++)
			cout << matriz[i][j] << "  ";
	}
	cout << "\n   a  e  i  o  u\n\n";
	
	system ("pause");
}
