/*
Indique cu�l ser�a el resultado
de las siguientes operaciones:
*/

#include <iostream>

using namespace std;

int main (){
	int salario_base;
	int salario_final;
	int incremento;
	
	salario_base = 1000;
	salario_final = salario_base;
	
	incremento = 200;
	salario_final = salario_final + incremento;
	
	salario_base = 3500;
	
	cout << "\nSalario base: " << salario_base;
	cout << "\nSalario final: " << salario_final << "\n\n";
	
	system ("pause");
}

/*
El resultado de las operaciones es:
salario_base = 3500
salario_final = 1200
*/

/*
El hecho de realizar la asignaci�n salario_final = salario_base
no hace que ambas variables est�n ligadas durante todo el programa,
ya que despu�s adquieren ambas nuevos valores.
Cualquier modificaci�n posterior de salario_base no afecta a
salario_final, puesto que las sentencias se ejecutan de manera ordenada
y tras la primera asignaci�n ambas variables adquieren valores distintos,
los cuales no afectan posteriormente a la varible a la que no se ha asignado
ese valor.
*/
