/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión
Ejercicio 28: Población con una clase

Recupere la solución del ejercicio 10 de esta relación de problemas (población con funciones). 
Re-escríbalo para que los cómputos relacionados con la población estén encapsulados en una clase. 
La lectura de los valores en los rangos adecuados se hará con las mismas funciones que ya se definieron 
en ese ejercicio. 
Modifique apropiadamente el programa principal

*/

#include <iostream>
using namespace std;

class Poblacion{
	private:
		long long poblacion_inicial;
		long long poblacion_futura;
		long long poblacion_duplicada;
		int anios_transcurridos;
		int tasa_natalidad;
		int tasa_mortalidad;
		int tasa_migracion;

	
	public:		
		void SetTasasPoblacion(long long la_poblacion_inicial, int la_tasa_natalidad, int la_tasa_mortalidad, int la_tasa_migracion){
			poblacion_inicial = la_poblacion_inicial;
			tasa_natalidad = la_tasa_natalidad;
			tasa_mortalidad = la_tasa_mortalidad;
			tasa_migracion = la_tasa_migracion;
		}
		
		double IndiceVariacion(){
			int tasa_global;
			double IV_tasa_global;
	
			tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
			IV_tasa_global = 1 + tasa_global / 1000.0;
	
			return IV_tasa_global;
		}
		
		void PoblacionFutura (int anios){
			double IV_tasa_global;
			long long poblacion_en_el_futuro;
	
			IV_tasa_global = IndiceVariacion();
			poblacion_en_el_futuro = poblacion_inicial;
	
			for (int i = 1 ; i <= anios ; i++){
				poblacion_en_el_futuro = poblacion_en_el_futuro * IV_tasa_global;	
			}
			poblacion_futura = poblacion_en_el_futuro;
		}
		
		void PoblacionDuplicada (){
			double IV_tasa_global;
			long long poblacion_futura_2, doble_poblacion;
			int i;
	
			poblacion_futura_2 = poblacion_inicial;
			doble_poblacion = 2 * poblacion_inicial;
			IV_tasa_global = IndiceVariacion();
	
			for (i = 0 ; poblacion_futura_2 <= doble_poblacion ; i++){
				poblacion_futura_2 = poblacion_futura_2 * IV_tasa_global;
			}
			
			anios_transcurridos = i;
			poblacion_duplicada = poblacion_futura_2;
		}
		
		long long GetPoblacionFutura(){
			return poblacion_futura;
		}
		
		long long GetPoblacionInicial(){
			return poblacion_inicial;
		}
	
		long long GetPoblacionDuplicada(){
			return poblacion_duplicada;
		}

		int GetAniosTranscurridos(){
			return anios_transcurridos;
		}
};

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

int main(){
	//Declaración de variables 
	long long poblacion_inicial;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, anios;
   Poblacion poblacion;
   
   cout << "Calculo de la poblacion futura \n\n";
   
   // Entrada de datos   
   cout << "Introduzca la poblacion actual: ";   
   poblacion_inicial = LeeIntMayorIgualQue(0);
   
   cout << "Introduzca la tasa de natalidad: ";
   tasa_natalidad = LeeIntRango(0, 1000);
	
   cout << "Introduzca la tasa de mortalidad: ";
   tasa_mortalidad = LeeIntRango(0, 1000);
	
   cout << "Introduzca la tasa de migracion: ";
   tasa_migracion = LeeIntRango(0, 1000);
	
	cout << "Introduzca el numero de anios que deben pasar para el calculo: ";
	anios = LeeIntMayorIgualQue(0);
	
	// Cómputos
	poblacion.SetTasasPoblacion(poblacion_inicial, tasa_natalidad, tasa_mortalidad, tasa_migracion);
	poblacion.PoblacionFutura(anios);
	poblacion.PoblacionDuplicada();
	
	// Salida de resultados	
	cout << "\n\nLa poblacion, pasados " << anios << " anios, sera de: " << poblacion.GetPoblacionFutura() << "\n" << endl <<
			  "La poblacion inicial se duplicara transcurridos " << poblacion.GetAniosTranscurridos() << " anios," << endl << 
			  "y esta sera: " << poblacion.GetPoblacionDuplicada() << "\n\n";

	system ("pause");
}
