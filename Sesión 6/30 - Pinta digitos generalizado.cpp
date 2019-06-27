/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 30: Pinta dígitos generalizado
Programa que lee un valor entero cualquiera e imprime 
los dígitos separados por un espacio en blanco. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int numero, numero_copia, numero_digitos, digito_a_imprimir, exponente, potencia;
	
	// Entrada de datos
	
	cout << "Programa que lee un numero entero e imprime sus cifras separadas por un espacio en blanco ";
	cout << "\nIntroduzca un numero entero: ";
	cin >> numero;
	
	// Cómputos
	
	numero_copia = numero;
	numero_digitos = 1;
	
	while (numero_copia > 9){
		numero_copia = numero_copia / 10;
		numero_digitos++;
	}
	
	numero_copia = numero;
	
	// Cómputos con salida de resultados
	
	while (numero_copia > 0){
		exponente = numero_digitos - 1;
		potencia = pow(10,exponente);
		digito_a_imprimir = numero_copia / potencia;
		cout << digito_a_imprimir << "   ";
		numero_digitos--;
		numero_copia = numero_copia % potencia;
	}
	
	cout << "\n\n";
	
	system ("pause");
}
