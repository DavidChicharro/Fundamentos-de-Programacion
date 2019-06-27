#include <iostream>

using namespace std;

int main(){
	int hora_inicial, minuto_inicial, segundo_inicial;
	int hora_final, minuto_final, segundo_final;
	int segundos_iniciales, segundos_finales;
	int diferencia;
	
	cout << "Este programa calculara la diferencia en segundos entre dos instantes de un dia \n"
		  << endl << "Las horas van de 0 a 23, y los minutos y segundos de 0 a 59 \n"
		  << endl << "Establezca el primer momento del dia \n";
		  
	cout << "Inserte la hora ";
	cin >> hora_inicial;
	cout << "Inserte los minutos ";
	cin >> minuto_inicial;
	cout << "Inserte los segundos ";
	cin >> segundo_inicial;
	
	cout << "\nA continuacion debe establecer el segundo momento del dia \n";
	cout << "Inserte la hora ";
	cin >> hora_final;
	cout << "Inserte los minutos ";
	cin >> minuto_final;
	cout << "Inserte los segundos ";
	cin >> segundo_final;
	
	segundos_iniciales = hora_inicial * 60 * 60 +
								minuto_inicial * 60 +
								segundo_inicial ;
								
	segundos_finales = hora_final * 60 * 60 +
							 minuto_final * 60 +
							 segundo_final ;
							 
	diferencia = segundos_finales - segundos_iniciales;							 							
	
	cout << "\nEl numero de segundos entre ambos instantes es " << diferencia << "\n\n";
	
	system ("pause");
}
