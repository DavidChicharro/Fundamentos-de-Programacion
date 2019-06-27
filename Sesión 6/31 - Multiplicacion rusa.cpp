/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 31: Multiplicación rusa

Este programa calcula el producto de dos numeros mediante
el método de la multiplicación rusa.
Se leen los dos valores de entrada, que son los dos factores.
El algoritmo calcula el doble del segundo multiplicador (m) y la parte 
entera de la mitad del primer factor (n), hasta que este tome el valor 1.
El resultado será la suma de los multiplicadores (m) cuyo multiplicando (n) sea impar.
*/

#include <iostream>

using namespace std;

int main(){
	int factor_1, factor_2, n, m, suma;
	
	//Entrada de datos
	
	cout << "Inserte el primer factor de la multiplicacion: ";
	cin >> factor_1;
	cout << "Inserte el segundo factor de la multiplicacion: ";
	cin >> factor_2;
	
	// Cómputos
	
	n = factor_1;
	m = factor_2;
	suma = 0;
	
	do{
		if (n % 2 != 0)
			suma = suma + m;
		
		n = n / 2;
		m = m + m;
	}while (n > 0);
	
	// Salida de resultados
	
	cout << "El productor entre " << factor_1 << " y " << factor_2 << " es: " << suma << "\n\n";
	
	system ("pause");
}
