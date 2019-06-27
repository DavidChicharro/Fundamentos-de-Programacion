/*
Se subirá el sueldo:
	4% a quienes hayan resuelto más de 30 casos
	3% a quienes hayan resuelto entre 20 y 30 casos
	2% si el grado de satisfacción medio es mayor o igual que 4.0
Todas las subidas son compatibles.
*/

#include <iostream>

using namespace std;

int main(){
	const int LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS = 30,
				 LIMITE_INFERIOR_POCOS_CASOS_RESUELTOS = 20;
	const double LIMITE_INFERIOR_GRADO_SATISFACCION = 4.0;
	
	const double PORCENTAJE_SUBIDA_MUCHOS_CASOS_RESUELTOS = 0.04,
					 PORCENTAJE_SUBIDA_MEDIA_CASOS_RESUELTOS = 0.03,					// Entre 20 y 30 casos resueltos
					 PORCENTAJE_SUBIDA_ALTO_GRADO_SATISFACCION = 0.02;
					 
	double salario_por_hora, grado_satisfaccion,
			 salario_base, porcentaje_incremento, salario_final;
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
	
	porcentaje_incremento = 0.0;
	salario_base = salario_por_hora * horas_trabajadas_mes;
	
	if (casos_resueltos > LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS)
		porcentaje_incremento = PORCENTAJE_SUBIDA_MUCHOS_CASOS_RESUELTOS;
	else if (casos_resueltos >= LIMITE_INFERIOR_POCOS_CASOS_RESUELTOS && casos_resueltos <= LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS)
		porcentaje_incremento = PORCENTAJE_SUBIDA_MEDIA_CASOS_RESUELTOS;
		
	if (grado_satisfaccion >= LIMITE_INFERIOR_GRADO_SATISFACCION)
		porcentaje_incremento = porcentaje_incremento + PORCENTAJE_SUBIDA_ALTO_GRADO_SATISFACCION;
		
	salario_final = salario_base * (1 + porcentaje_incremento);
	
	// Salida de resultados:	
		
	cout << "\nEl salario del trabajador sera de " << salario_final << " euros \n\n";
	
	system ("pause");
}
