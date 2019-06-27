/*
La tabla para el cálculo del precio a pagar en los parkings
de Madrid para el 2015 es la siguiente:
	Si permanece más de 660 minutos se paga una única tarifa de 31.55 euros
	Desde el minuto 0 al 30: 0.0412 euros cada minuto
	Desde el minuto 31 al 90: 0.0370 euros cada minuto
	Desde el minuto 91 al 120: 0.0311 euros cada minuto
	Desde el minuto 121 al 660: 0.0305 euros cada minuto
*/

#include <iostream>

using namespace std;

int main(){
	int hora_inicial, minuto_inicial, segundo_inicial;
	int hora_final, minuto_final, segundo_final;
	int segundos_iniciales, segundos_finales, diferencia;
	const int SEGUNDOS_EN_MINUTO = 60, MINUTOS_EN_HORA = 60;
	int minutos;
	double tarifa;
	const double TARIFA_1 = 0.0412, TARIFA_2 = 0.037, TARIFA_3 = 0.0311, TARIFA_4 = 0.0305, TARIFA_5 = 31.55;
	
	// Entrada de datos:
		  
	cout << "CALCULADOR DE TARIFAS DE PARKING";
	cout << "\n\nIndique el momento de entrada en el parking \n";
	cout << "Inserte la hora ";
	cin >> hora_inicial;
	cout << "Inserte los minutos ";
	cin >> minuto_inicial;
	cout << "Inserte los segundos ";
	cin >> segundo_inicial;
	
	cout << "\nAhora indique el momento de salida del parking \n";
	cout << "Inserte la hora ";
	cin >> hora_final;
	cout << "Inserte los minutos ";
	cin >> minuto_final;
	cout << "Inserte los segundos ";
	cin >> segundo_final;
	
	// Cómputos:
	
	segundos_iniciales = hora_inicial * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO +
								minuto_inicial * SEGUNDOS_EN_MINUTO +
								segundo_inicial ;
								
	segundos_finales = hora_final * MINUTOS_EN_HORA * SEGUNDOS_EN_MINUTO +
							 minuto_final * SEGUNDOS_EN_MINUTO +
							 segundo_final ;
							 
	diferencia = segundos_finales - segundos_iniciales;
	minutos = diferencia / SEGUNDOS_EN_MINUTO;
	
	if (minutos > 0 && minutos <=30)
		tarifa = minutos * TARIFA_1;
	else if (minutos >= 31 && minutos <= 90)
		tarifa = minutos * TARIFA_2;
	else if (minutos >= 91 && minutos <= 120)
		tarifa = minutos * TARIFA_3;
	else if (minutos >= 121 && minutos <= 660)
		tarifa = minutos * TARIFA_4;
	else
		tarifa = TARIFA_5;
		
	// Salida de resultados:	
	
	cout << "\nLa tarifa es de " << tarifa << " euros ";
	cout << "\n\nFin del programa \n\n";
	
	system ("pause");
}
