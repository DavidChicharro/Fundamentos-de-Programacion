/*
Queremos gestionar la n�mina de los empleados de un centro de atenci�n telef�nica.
Construya un programa que lea el salario por hora (dato de tipo real) de un empleado,
el n�mero de horas trabajadas durante el mes actual (dato de tipo entero), 
el n�mero de casos resueltos de forma satisfactoria (dato de tipo entero)
y el grado medio de satisfacci�n de los usuarios de los servicios telef�nicos con el
empleado en cuesti�n (real entre 0 y 5).

Se quiere aplicar una subida salarial en funci�n de varios factores. En ejercicios sucesivos
se ir�n planteando distintas posibilidades. La primera que se quiere implementar es la siguiente:
Se aplicar� una subida del 4% a los empleados que han resuelto m�s de 30 casos.
*/

#include <iostream>

using namespace std;

int main(){
	double salario_por_hora, grado_satisfaccion;
	double salario_base, salario_final;
	int horas_trabajadas_mes, casos_resueltos;
	
	// Entrada de datos:
	
	cout << "Programa para gestionar la nomina de los empleados \n\n";
	cout << "\nIntroduzca el salario por hora del empleado: ";
	cin >> salario_por_hora;
	cout << "Indique el numero de horas trabajadas durante el mes actual: ";
	cin >> horas_trabajadas_mes;
	cout << "Indique el numero de casos resueltos satisfactoriamente: ";
	cin >> casos_resueltos;
	cout << "Indique el grado medio de satisfaccion de los usuarios con el empleado: ";
	cin >> grado_satisfaccion;
	
	// C�mputos:
	
	salario_base = salario_por_hora * horas_trabajadas_mes;
	
	if (casos_resueltos > 30)
		salario_final = salario_base * 1.04;
	else
		salario_final = salario_base;
	
	// Salida de resultados:
		
	cout << "\nEl salario del trabajador sera de " << salario_final << " euros \n\n";
	
	system ("pause");
}
