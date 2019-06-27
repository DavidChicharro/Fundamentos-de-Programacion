/*
Programa que lee desde teclado tres variables correspondientes a un n�mero de horas,
minutos y segundos, respectivamente. A continuaci�n, el programa debe calcular las
horas, minutos y segundos dentro de su rango correspondiente.
El programa no calcular� meses, a�os, etc. sino que se quedar� en los d�as.
*/

#include <iostream>

using namespace std;

int main(){
	const int MINUTOS_EN_HORA = 60, SEGUNDOS_EN_MINUTO = 60, HORAS_EN_DIA = 24 ;
	int horas_iniciales, minutos_iniciales, segundos_iniciales;
	int segundos_totales, horas_aux, minutos_aux;
	int dias, horas, minutos, segundos;
	
	
	cout << "Este programa calcula un numero de horas, minutos y segundos cualesquiera en su rango correspondiente \n\n";
	cout << "Introduzca el numero de horas ";
	cin >> horas_iniciales;
	cout << "Introduzca el numero de minutos ";
	cin >> minutos_iniciales;
	cout << "Introduzca el numero de segundos ";
	cin >> segundos_iniciales;
	
	
	segundos_totales = horas_iniciales * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO +
							 minutos_iniciales * SEGUNDOS_EN_MINUTO +
							 segundos_iniciales;
	
	dias = segundos_totales / (HORAS_EN_DIA * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);			// Se obtiene un valor entero que corresponde al n� de d�as
	horas_aux = segundos_totales % (HORAS_EN_DIA * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);  // Almacena un n� de segundos restantes inferior al n� de segundos que hay en un d�a
	horas = horas_aux / (MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);										// Se obtiene un valor correspondiente al n�mero de horas
	minutos_aux = horas_aux % (MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);								// Almacena un n� de segundos restantes inferior al n� de segundos que hay en una hora
	minutos = minutos_aux / (SEGUNDOS_EN_MINUTO);														// Se obtiene un valor correspondiente al n�mero de minutos
	segundos = minutos_aux % (SEGUNDOS_EN_MINUTO);														// El resto equivale a los segundos restantes
	
	
	cout << "\n\nEquivale a " << dias << " dias, " << horas << " horas, "
		  << minutos << " minutos y " << segundos << " segundos" << "\n\n";
		  
	system ("pause");
}
