/*
Ampliaci�n ejercicio 12 (Poblaci�n)
Adem�s de los datos ya pedidos en dicho ejercicio, se le pedir� al usuario que 
introduzca un n�mero de a�os. Debe leer cada dato con un filtro conveniente. 
Las tasas de natalidad, mortalidad y emigraci�n deben ser enteros entre 0 y 1000, 
mientras que la poblaci�n inicial debe ser un entero positivo.
El programa debe calcular e imprimir el n�mero total de habitantes transcurridos dichos a�os.
Adem�s, el programa tambi�n calcular� el n�mero de a�os que tienen que pasar
hasta que haya, como m�nimo, el doble de la poblaci�n inicial.
*/

#include <iostream>

using namespace std;

int main(){
	long long poblacion_inicial, poblacion_futura, poblacion_duplicada, poblacion_futura_2;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global,
		 anios, incremento_anio, anios_transcurridos;
   double indice_variacion_tasa_global;
   
   cout << "Calculo de la poblacion futura \n\n";
   cout << "Introduzca la poblacion actual: ";
   
   do{
		cin  >> poblacion_inicial;
	}while(poblacion_inicial < 0);
	
   cout << "Introduzca la tasa de natalidad: ";
   
   do{
		cin  >> tasa_natalidad;
	}while (tasa_natalidad < 0 || tasa_natalidad > 1000);
	
   cout << "Introduzca la tasa de mortalidad: ";
   
   do{
		cin  >> tasa_mortalidad;
	}while (tasa_mortalidad < 0 || tasa_mortalidad > 1000);
	
   cout << "Introduzca la tasa de migracion: ";
   
   do{
		cin  >> tasa_migracion;
	}while (tasa_migracion < 0 || tasa_migracion > 1000);
	
	cout << "Introduzca el numero de anios que deben pasar para el calculo: ";
	cin >> anios;
	
	tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
	indice_variacion_tasa_global = 1 + tasa_global / 1000.0;
	poblacion_futura = poblacion_inicial;
	incremento_anio = 1;

	
	while (incremento_anio <= anios){
		poblacion_futura = poblacion_futura * indice_variacion_tasa_global;
		incremento_anio++;
	}
	
	poblacion_duplicada = 2 * poblacion_inicial;
	poblacion_futura_2 = poblacion_inicial;
	anios_transcurridos = 0;
	
	while (poblacion_futura_2 <= poblacion_duplicada){
		poblacion_futura_2 = poblacion_futura_2 * indice_variacion_tasa_global;
		anios_transcurridos++;
	}
	
	cout << "\n\nLa poblacion, pasados " << anios << " anios, sera de: " << poblacion_futura << "\n";
	cout << "La poblacion inicial se duplicara transcurridos " << anios_transcurridos << " anios," << endl;
	cout << "y esta sera: " << poblacion_futura_2 << "\n\n";
	
	system ("pause");
}
