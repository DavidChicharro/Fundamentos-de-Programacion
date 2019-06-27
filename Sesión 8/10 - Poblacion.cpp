/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 8
Ejercicio 10: Poblaci�n

Programa que pide tasas de poblaci�n y un n�mero de a�os y calcula
el n�mero de habitantes transcurridos dichos a�os. Tambi�n calcula el
n�mero de a�os que transcurrir�n hasta que la poblaci�n inicial se duplique
Se imprimir�n en pantalla los resultados de la poblaci�n futura, el n�mero 
de a�os que transcurrir�n hasta que se duplique y el n�mero de habitantes una vez duplicada.

*/

#include <iostream>

using namespace std;


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

double IndiceVariacion (int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
	int tasa_global;
	double IV_tasa_global;
	
	tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
	IV_tasa_global = 1 + tasa_global / 1000.0;
	
	return IV_tasa_global;
}

long long PoblacionFutura (long long poblacion_inicial, int tasa_natalidad, int tasa_mortalidad, int tasa_migracion, int anios){
	double IV_tasa_global;
	long long poblacion_futura;
	
	IV_tasa_global = IndiceVariacion(tasa_natalidad, tasa_mortalidad, tasa_migracion);
	poblacion_futura = poblacion_inicial;
	
	for (int i = 1 ; i <= anios ; i++){
		poblacion_futura = poblacion_futura * IV_tasa_global;	
	}
	
	return poblacion_futura;
}

long long PoblacionDuplicada (long long poblacion_inicial, long long doble_poblacion, int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
	double IV_tasa_global;
	long long poblacion_futura_2;
	int i;
	
	poblacion_futura_2 = poblacion_inicial;
	IV_tasa_global = IndiceVariacion(tasa_natalidad, tasa_mortalidad, tasa_migracion);
	
	for (i = 0 ; poblacion_futura_2 <= doble_poblacion ; i++){
		poblacion_futura_2 = poblacion_futura_2 * IV_tasa_global;
	}
	
	return poblacion_futura_2;
}

int AniosTranscurridos (long long poblacion_inicial, long long doble_poblacion, int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
	double IV_tasa_global;
	long long poblacion_futura_2;
	int i;
	
	poblacion_futura_2 = poblacion_inicial;
	IV_tasa_global = IndiceVariacion(tasa_natalidad, tasa_mortalidad, tasa_migracion);
	
	for (i = 0 ; poblacion_futura_2 <= doble_poblacion ; i++){
		poblacion_futura_2 = poblacion_futura_2 * IV_tasa_global;
	}
	
	return i;
}

int main(){
	//Declaraci�n de variables 
	long long poblacion_inicial, poblacion_futura, doble_poblacion, poblacion_duplicada;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, anios, anios_transcurridos;
   
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
	
	// C�mputos	
	poblacion_futura = PoblacionFutura(poblacion_inicial, tasa_natalidad, tasa_mortalidad, tasa_migracion, anios);
	doble_poblacion = poblacion_inicial * 2;
	poblacion_duplicada = PoblacionDuplicada(poblacion_inicial, doble_poblacion, tasa_natalidad, tasa_mortalidad, tasa_migracion);
	anios_transcurridos = AniosTranscurridos(poblacion_inicial, doble_poblacion, tasa_natalidad, tasa_mortalidad, tasa_migracion);
	
	// Salida de resultados	
	cout << "\n\nLa poblacion, pasados " << anios << " anios, sera de: " << poblacion_futura << "\n";
	cout << "La poblacion inicial se duplicara transcurridos " << anios_transcurridos << " anios," << endl;
	cout << "y esta sera: " << poblacion_duplicada << "\n\n";
	
	system ("pause");
}
