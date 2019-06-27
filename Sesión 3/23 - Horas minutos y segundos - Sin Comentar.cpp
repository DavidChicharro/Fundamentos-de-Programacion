/*
Programa que lee desde teclado tres variables correspondientes a un número de horas,
minutos y segundos, respectivamente. A continuación, el programa debe calcular las
horas, minutos y segundos dentro de su rango correspondiente.
El programa no calculará meses, años, etc. sino que se quedará en los días.
*/

#include <iostream>

using namespace std;

int main(){
	const int MINUTOS_EN_HORA = 60, SEGUNDOS_EN_MINUTO = 60, HORAS_EN_DIA = 24 ;
	int horas_iniciales, minutos_iniciales, segundos_iniciales;
	int segundos_totales, horas_aux, minutos_aux;
	int dias, horas, minutos, segundos;
	
	
	cout << "Este programa calcula un numero de horas, minutos y segundos cualquiera en su rango correspondiente \n\n";
	cout << "\nIntroduzca el numero de horas ";
	cin >> horas_iniciales;
	cout << "\nIntroduzca el numero de minutos ";
	cin >> minutos_iniciales;
	cout << "\nIntroduzca el numero de segundos ";
	cin >> segundos_iniciales;
	
	
	segundos_totales = horas_iniciales * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO +
										  minutos_iniciales * SEGUNDOS_EN_MINUTO +
										  segundos_iniciales;
	
	dias = segundos_totales / (HORAS_EN_DIA * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);
	horas_aux = segundos_totales % (HORAS_EN_DIA * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);
	horas = horas_aux / (MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);
	minutos_aux = horas_aux % (MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO);
	minutos = minutos_aux / (SEGUNDOS_EN_MINUTO);
	segundos = minutos_aux % (SEGUNDOS_EN_MINUTO);
	
	
	cout << "La diferencia es de " 
		  << dias << " dias, "
		  << horas << " horas, "
		  << minutos << "minutos y "
		  << segundos << " segundos"
		  << "\n\n";
		  
	system ("pause");
}
	
	
	
