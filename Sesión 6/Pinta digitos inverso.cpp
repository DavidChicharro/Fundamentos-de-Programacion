/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 30***: Pinta digitos inverso xd

*/

#include <iostream>

using namespace std;

int main(){
	int numero, numero_copia, numero_digitos, ultimo_digito, i;
	
	cout << "Programa que lee un numero entero e imprime sus cifras separadas por un espacio en blanco ";
	cout << "\nIntroduzca un numero entero: ";
	cin >> numero;
	
	numero_copia = numero;
	numero_digitos = 1;
	
	while (numero_copia > 9){
		numero_copia = numero_copia / 10;
		numero_digitos++;
	}
	
	numero_copia = numero;
	
	for (i = 1 ; numero_digitos >= i ; i++){
		ultimo_digito = numero_copia % 10;
		cout << ultimo_digito << "   ";
		numero_copia = numero_copia / 10;
	}
	
	system ("pause");
}
