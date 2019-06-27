/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 8
Ejercicio 11: Aumento salarial centro de atención telefónica

Programa que calcula el salario final de unos trabajadores a partir de datos de entrada 
relacionados con su trabajo, tales como son el tiempo de las llamadas, la satisfacción 
de los usuarios y si fueron capaces de resolver el caso. Estos datos influirán en las subidas 
de sus salarios, los cuales se imprimirán en pantalla, mostrando además quién fue el mejor trabajador.

*/

#include <iostream>

using namespace std;

double LeeDoubleMayorIgualQue(int minimo){
	double a_leer;
	
	do{
		cin >> a_leer;
	}while (a_leer < minimo);
	
	return a_leer;	
}

int LeeIntMayorIgualQue(int minimo){
	int a_leer;
	
	do{
		cin >> a_leer;
	}while (a_leer < minimo);
	
	return a_leer;	
}

int LeeIntRango(int minimo, int maximo){
	int a_leer;
	
	do{
		cin >> a_leer;
	}while (a_leer < minimo || a_leer > maximo);
	
	return a_leer;	
}

double HorasTrabajadas(int duracion_llamadas){
	const double SEGUNDOS_EN_MINUTO = 60.0, MINUTOS_EN_HORA = 60.0;
	double horas_trabajadas;

	horas_trabajadas = duracion_llamadas / (SEGUNDOS_EN_MINUTO * MINUTOS_EN_HORA);
	
	return horas_trabajadas;
}

double SalarioFinal(double salario_hora, int duracion_llamadas, int casos_resueltos, double grado_satisfaccion){
	const int LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS = 30,
				 LIMITE_INFERIOR_POCOS_CASOS_RESUELTOS = 20;
	const double LIMITE_INFERIOR_GRADO_SATISFACCION = 4.0;
	
	const double PORCENTAJE_SUBIDA_MUCHOS_CASOS_RESUELTOS = 0.04,
					 PORCENTAJE_SUBIDA_MEDIA_CASOS_RESUELTOS = 0.03,					// Entre 20 y 30 casos resueltos
					 PORCENTAJE_SUBIDA_ALTO_GRADO_SATISFACCION = 0.02;
	double porcentaje_incremento, salario_base, salario_final;
	
	porcentaje_incremento = 0.0;
	salario_base = salario_hora * HorasTrabajadas(duracion_llamadas);
	
	if (casos_resueltos > LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS)
		porcentaje_incremento = PORCENTAJE_SUBIDA_MUCHOS_CASOS_RESUELTOS;
	else if (casos_resueltos >= LIMITE_INFERIOR_POCOS_CASOS_RESUELTOS && casos_resueltos <= LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS)
		porcentaje_incremento = PORCENTAJE_SUBIDA_MEDIA_CASOS_RESUELTOS;
		
	if (grado_satisfaccion >= LIMITE_INFERIOR_GRADO_SATISFACCION)
		porcentaje_incremento = porcentaje_incremento + PORCENTAJE_SUBIDA_ALTO_GRADO_SATISFACCION;
		
	salario_final = salario_base * (1 + porcentaje_incremento);
	
	return salario_final;	
}

int main(){
	double salario_hora, satisfaccion_media_empleado_1, satisfaccion_media_empleado_2, 
			 satisfaccion_media_empleado_3, satisfaccion_maxima,
			 salario_final_1, salario_final_2, salario_final_3;
	int codigo_empleado, casos_totales, casos_1, casos_2, casos_3, 
		 duracion_llamada, grado_satisfaccion, caso_resuelto, 
		 satisfaccion_empleado_1, satisfaccion_empleado_2, satisfaccion_empleado_3, mejor_empleado,
		 duracion_llamada_1, duracion_llamada_2, duracion_llamada_3,
		 casos_resueltos_1, casos_resueltos_2, casos_resueltos_3; 
	const int TERMINADOR = -1;
	bool continuar;
	
	cout << "Introduzca un salario por hora: ";
	salario_hora = LeeDoubleMayorIgualQue(0);
	
	casos_1 = 0;
	casos_2 = 0;
	casos_3 = 0;
	satisfaccion_empleado_1 = 0;
	satisfaccion_empleado_2 = 0;
	satisfaccion_empleado_3 = 0;
	duracion_llamada_1 = 0; 
	duracion_llamada_2 = 0;
	duracion_llamada_3 = 0;
	casos_resueltos_1 = 0; 
	casos_resueltos_2 = 0;
	casos_resueltos_3 = 0;
	
	do{
		cout << "\nIntroduzca el codigo del empleado: ";
		cin >> codigo_empleado;
		
		continuar = (codigo_empleado != TERMINADOR);
		
		if (continuar){
			cout << "Indique cuanto duro la llamada (en segundos): ";
			duracion_llamada = LeeIntMayorIgualQue(0);
			
			cout << "Indique si el caso fue ruelto positivamente [1] o si no fue resuelto [0]: ";
			caso_resuelto = LeeIntRango(0, 1);
			
			cout << "Indique el grado de satisfaccion del usuario (entre 0 y 5): ";
			grado_satisfaccion = LeeIntRango(0, 5);
			
			if (codigo_empleado == 1){
				satisfaccion_empleado_1 = satisfaccion_empleado_1 + grado_satisfaccion;
				duracion_llamada_1 = duracion_llamada_1 + duracion_llamada;
				
				if (caso_resuelto == 1)
					casos_resueltos_1++;
					
				casos_1++;
			}			
			else if (codigo_empleado == 2){
				satisfaccion_empleado_2 = satisfaccion_empleado_2 + grado_satisfaccion;
				duracion_llamada_2 = duracion_llamada_2 + duracion_llamada;
				
				if (caso_resuelto == 1)
					casos_resueltos_2++;
					
				casos_2++;
			}
			else if (codigo_empleado == 3){
				satisfaccion_empleado_3 = satisfaccion_empleado_3 + grado_satisfaccion;
				duracion_llamada_3 = duracion_llamada_3 + duracion_llamada;
				if (caso_resuelto == 1)
					casos_resueltos_3++;
					
				casos_3++;
			}
		}
	}while (continuar);
	
	casos_totales = casos_1 + casos_2 + casos_3;
	
	if (casos_totales > 0){
		satisfaccion_media_empleado_1 = satisfaccion_empleado_1 / (1.0 * casos_1);
		satisfaccion_media_empleado_2 = satisfaccion_empleado_2 / (1.0 * casos_2);
		satisfaccion_media_empleado_3 = satisfaccion_empleado_3 / (1.0 * casos_3);
	
		satisfaccion_maxima = satisfaccion_media_empleado_1;
		mejor_empleado = 1;
	
		if (satisfaccion_media_empleado_1 < satisfaccion_media_empleado_2){
			satisfaccion_maxima = satisfaccion_media_empleado_2;
			mejor_empleado = 2;
		}
		else{
			if (casos_3 != 0){
				satisfaccion_maxima = satisfaccion_media_empleado_3;
				mejor_empleado = 3;
			}
		}
	
		salario_final_1 = SalarioFinal(salario_hora, duracion_llamada_1, casos_resueltos_1, satisfaccion_media_empleado_1);
		salario_final_2 = SalarioFinal(salario_hora, duracion_llamada_2, casos_resueltos_2, satisfaccion_media_empleado_2);
		salario_final_3 = SalarioFinal(salario_hora, duracion_llamada_3, casos_resueltos_3, satisfaccion_media_empleado_3);
		
	
		cout << "\n\nSe han introducido " << casos_totales << " casos ";
		cout << "\nEl empleado " << mejor_empleado << " es quien tiene el mayor grado de satisfaccion medio, que es: " 
		 	  << satisfaccion_maxima << "\n\n";
		cout << "\nEl salario del trabajador 1 sera de " << salario_final_1 << " euros";
		cout << "\nEl salario del trabajador 2 sera de " << salario_final_2 << " euros";
		cout << "\nEl salario del trabajador 3 sera de " << salario_final_3 << " euros \n\n";
	}
	else
		cout << "\nNo se introdujo ningun caso \n\n";

	system ("pause");
}
