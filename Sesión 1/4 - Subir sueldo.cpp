/*Programa para leer el valor de una variable
salario_base de tipo double, que se incremente
un 2% e imprima el resultado en pantalla*/

#include <iostream>

using namespace std;

int main(){
	const double INCREMENTO = 1.02 ;
	double salario_base, salario_final ;
	
	cout << "Introduzca el salario base " ;
	cin >> salario_base ;
	
	salario_final = salario_base * INCREMENTO ;								
	
	cout << "El salario final es " <<  salario_final << "\n\n" ;

	system ("pause") ;
}


/*
Para realizar el ejercicio la opción escogida es la b), puesto que es
más cómodo declarar una variable al principio como constante, en este
caso "INCREMENTO", de modo que se le asigna un valor y se utiliza su
nombre posteriormente en lugar del valor numérico. Además, en caso de 
tener que ser utilizada posteriormente en varias ocasiones en el programa
y modificado su valor en otro momento, resulta menos engorroso cambiar
el valor de la constante una sola vez, en lugar de hacerlo en todas las
sentencias donde haya sido utilizado.
*/
