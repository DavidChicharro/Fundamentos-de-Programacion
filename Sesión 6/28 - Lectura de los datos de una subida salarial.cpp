/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 28: Lectura de los datos de la subida salarial
Este programa leerá los datos de 3 empleados identificados con un código.
En primer lugar se introducirá el salario por hora, que será el mismo para todos.
Después se leerán los datos de los casos atendidos por los empleados; primero e introducirá el código del empleado y
posteriormente la duración de la conversación, si se resolvió el caso y el grado de satisfacción del usuario.
El terminador -1 en el código del empleado hará que termine la introducción de datos.

Se procederá a calcular la satisfacción media de cada empleado y se determinará quien tiene la media más alta.

Por último se imprimirá en pantalla el número de casos totales y se indicará quien fue el mejor empleado y su
grado medio de satisfacción por parte del usuario.

*/

#include <iostream>

using namespace std;

int main(){
	double salario_hora, satisfaccion_media_empleado_1, satisfaccion_media_empleado_2, 
			 satisfaccion_media_empleado_3, satisfaccion_maxima;
	int codigo_empleado, casos_totales, casos_1, casos_2, casos_3, 
		 duracion_llamada, grado_satisfaccion, caso_resuelto, 
		 satisfaccion_empleado_1, satisfaccion_empleado_2, satisfaccion_empleado_3, mejor_empleado;
	const int TERMINADOR = -1;
	bool continuar;
	
	cout << "Introduzca un salario por hora: ";
	cin >> salario_hora;
	
	casos_1 = 0;
	casos_2 = 0;
	casos_3 = 0;
	satisfaccion_empleado_1 = 0;
	satisfaccion_empleado_2 = 0;
	satisfaccion_empleado_3 = 0;
	
	do{
		cout << "\nIntroduzca el codigo del empleado: ";
		cin >> codigo_empleado;
		
		continuar = (codigo_empleado != TERMINADOR);
		
		if (continuar){
			cout << "Indique cuanto duro la llamada (en segundos): ";
			cin >> duracion_llamada;
			cout << "Indique si el caso fue ruelto positivamente [1] o si no fue resuelto [0]: ";
			cin >> caso_resuelto;
			cout << "Indique el grado de satisfaccion del usuario (entre 0 y 5): ";
			cin >> grado_satisfaccion;
			
			if (codigo_empleado == 1){
				satisfaccion_empleado_1 = satisfaccion_empleado_1 + grado_satisfaccion;
				casos_1++;
			}				
			else if (codigo_empleado == 2){
				satisfaccion_empleado_2 = satisfaccion_empleado_2 + grado_satisfaccion;
				casos_2++;
			}
			else if (codigo_empleado == 3){
				satisfaccion_empleado_3 = satisfaccion_empleado_3 + grado_satisfaccion;
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
			satisfaccion_maxima = satisfaccion_media_empleado_3;
			mejor_empleado = 3;
		}
	
		cout << "\n\nSe han introducido " << casos_totales << " casos ";
		cout << "\nEl empleado " << mejor_empleado << " es quien tiene el mayor grado de satisfaccion medio, que es: " 
		 	  << satisfaccion_maxima << "\n\n";
	}
	else
		cout << "\nNo se introdujo ningun caso \n\n";
	
	system ("pause");
}
