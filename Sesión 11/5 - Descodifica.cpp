/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 11
Ejercicio 5: Descodifica

Programa que lee un conjunto de caracteres con un mensaje cifrado hasta introducir '#'.
Otro vector almacenar� el mensaje descifrado. 
La forma de descifrado consiste en coger la primera y �ltima letra de cada palabra. 
Las palabras est�n separadas por uno o m�s espacios en blanco o el final del vector. 
Si la �ltima palabra no tiene espacios en blanco a su derecha, se coge s�lo el primer car�cter.
Por �ltimo el programa mostrar� la cadena descodificada.
*/

#include <iostream>
using namespace std;

int main(){	
	const char TERMINADOR = '#';
	const int TAMANIO = 1000;
	char vector[TAMANIO];
	int util_vector = 0,
		 util_vector_descodificado = 0;
	char vector_descodificado[util_vector];
	char caracter;
	
	cin.get(caracter);
	
	while (caracter != TERMINADOR){
		vector[util_vector] = caracter;
		
		util_vector++;
		
		cin.get(caracter);
	}
	
	for (int i = 0 ; i < util_vector ; i++){
		if ((vector[i] == '[' || vector[i] == ' ') && vector[i+1] != ']'){
			vector_descodificado[util_vector_descodificado] = vector[i+1];
			util_vector_descodificado++;
		}
		else if (vector[i+1] == ' ' && vector[i-1] != '[' ){
			vector_descodificado[util_vector_descodificado] = vector[i];
			util_vector_descodificado++;
		}
	}
	
	cout << "El mensaje descifrado es: ";
	for (int i = 0 ; i < util_vector_descodificado ; i++)
		cout << vector_descodificado[i];
	
	cout << "\n\n";
	
	system("pause");
}
