/*
Recupere la solución del ejercicio 5 sobre el cómputo de la nómina de los trabajadores
de un centro de atención telefónica. Implemente ahora el siguiente criterio para la
subida salarial. Se aplicará una subida del 4% a los empleados que han resuelto más
de 30 casos y una subida del 2% si el grado de satisfacción media de los usuarios
es mayor o igual que 4.0. Ambas subidas son compatibles, es decir, si un trabajador
cumple las dos condiciones, se le aplicarán ambas subidas.
Resuelva este ejercicio considerando que la nueva subida del 2% se realiza sobre el
salario inicial y no sobre el resultado de haber aplicado, en su caso, la otra subida del 4%.
*/

#include <iostream>

using namespace std;

int main(){
	double salario_por_hora, grado_satisfaccion;
	double salario_base, primera_subida, segunda_subida, salario_final;
	int horas_trabajadas_mes, casos_resueltos;
	
	//Entrada de datos:
	
	cout << "Programa para gestionar la nomina de los empleados \n\n";
	cout << "\nIntroduzca el salario por hora del empleado: ";
	cin >> salario_por_hora;
	cout << "Indique el numero de horas trabajadas durante el mes actual: ";
	cin >> horas_trabajadas_mes;
	cout << "Indique el numero de casos resueltos satisfactoriamente: ";
	cin >> casos_resueltos;
	cout << "Indique el grado medio de satisfaccion de los usuarios con el empleado: ";
	cin >> grado_satisfaccion;
	
	// Cómputos:
	
	salario_base = salario_por_hora * horas_trabajadas_mes;
	
	if (casos_resueltos > 30)
		primera_subida = salario_base * 0.04;
	else
		primera_subida = 0;
		
	if (grado_satisfaccion >= 4.0)
		segunda_subida = salario_base * 0.02;
	else
		segunda_subida = 0;
		
	salario_final = salario_base + primera_subida + segunda_subida;
	
	// Salida de resultados:	
		
	cout << "\nEl salario del trabajador sera de " << salario_final << " euros \n\n";
	
	system ("pause");
}
