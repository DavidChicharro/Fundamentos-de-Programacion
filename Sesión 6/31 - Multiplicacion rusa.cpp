/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 31: Multiplicaci�n rusa

Este programa calcula el producto de dos numeros mediante
el m�todo de la multiplicaci�n rusa.
Se leen los dos valores de entrada, que son los dos factores.
El algoritmo calcula el doble del segundo multiplicador (m) y la parte 
entera de la mitad del primer factor (n), hasta que este tome el valor 1.
El resultado ser� la suma de los multiplicadores (m) cuyo multiplicando (n) sea impar.
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
	
	// C�mputos
	
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
