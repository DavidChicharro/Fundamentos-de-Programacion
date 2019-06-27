/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 29: Mayor secuencia ascendente de temperaturas

El programa leerá una secuencia de temperaturas y calculará 
cuándo se produjo la mayor secuencia de días consecutivos 
con temperaturas crecientes. Al introducir -1 el programa acaba.
El programa nos debe decir la posición donde comienza la 
subsecuencia y su longitud.
*/

#include <iostream>

using namespace std;

int main(){
	double temperatura, temperatura_anterior;
	int dia_actual, dias_ascenso_consecutivo, longitud_ascenso, posicion_inicio, primer_dia_ascenso;
	const int TERMINADOR = -1;

	temperatura_anterior = 0;
	dias_ascenso_consecutivo = 0;
	longitud_ascenso = 0;
	posicion_inicio = 1;
	primer_dia_ascenso = 0;
	dia_actual = 0;

	//Entrada de datos y cómputos

	cout << "Inserte una temperatura: ";
	cin >> temperatura;
	
	while (temperatura != TERMINADOR){
		dia_actual++;
		
		if (temperatura > temperatura_anterior){
			dias_ascenso_consecutivo++;
			if (dias_ascenso_consecutivo > longitud_ascenso){
				longitud_ascenso = dias_ascenso_consecutivo;
				primer_dia_ascenso = posicion_inicio;
			}		
		}
		else{
			dias_ascenso_consecutivo = 1;
			posicion_inicio = dia_actual;
		}
		
		temperatura_anterior = temperatura;
		cout << "Inserte una nueva temperatura: ";
		cin >> temperatura;
	}	
	
	// Salida de resultados
	
	cout << "La mayor secuencia de subida de temperaturas empieza el dia " << primer_dia_ascenso << endl <<
	"y dura " << longitud_ascenso << " dias" << "\n\n";
	
	system ("pause");
}
