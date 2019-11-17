/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 12
Ejercicio 15 - Parking con un número variable de tramos

El programa pedirá que se introduzcan los límites máximos y las tarifas
de cada tramo horario de cobro para cada parking. Después se pedirá que 
se introduzcan las horas de entrada y salida del vehículo. El programa 
calculará la tarifa a aplicar según los tramos establecidos en cada parking.
Por último, se imprimirá en pantalla la tarifa a aplicar.

*/

#include <iostream>
using namespace std;

class TarifadoParking{
private:
	static const int TAMANIO = 50;
	double vector_tramos[TAMANIO];
	double vector_tarifas[TAMANIO];
	int total_utilizados;
	
public:
	TarifadoParking()
		:total_utilizados(0){
	}
	
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	int Capacidad(){
		return TAMANIO;
	}
	
	void AniadeTramo (double limite_superior_tramo, double tarifa_tramo){
		vector_tramos[total_utilizados] = limite_superior_tramo;
		vector_tarifas[total_utilizados] = tarifa_tramo;
		total_utilizados++;		
	}
	
	double GetTarifa(int minutos_estacionamiento){
		bool tiempo_limite_rebasado;
		bool continuar = true;
		double vector_minutos_tramo[TAMANIO] = {0};
		double tarifa = 0;
		
		tiempo_limite_rebasado = (minutos_estacionamiento > vector_tramos[total_utilizados - 2]);
		vector_tramos[-1] = 0;
		
		for (int i = 0 ; i < total_utilizados - 1 && !tiempo_limite_rebasado && continuar ; i++){
			if (minutos_estacionamiento < vector_tramos[i]){
				vector_minutos_tramo[i] = minutos_estacionamiento - vector_tramos[i-1];
				continuar = false;
			}
			else
				vector_minutos_tramo[i] = vector_tramos[i] - vector_tramos[i-1];
		}

	   if (tiempo_limite_rebasado)
   		tarifa = vector_tarifas[total_utilizados - 1];
		else
   		for (int i = 0 ; i < total_utilizados ; i++)
   			tarifa = tarifa + vector_minutos_tramo[i] * vector_tarifas[i];
		
		return tarifa;
	}
};

int MinutosEntreInstantes (int hora_inicial, int minuto_inicial, int segundo_inicial,
                           int hora_final, int minuto_final, int segundo_final){
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
   int segundos_iniciales, segundos_finales, segundos_diferencia;
   
   segundos_iniciales = SEGUNDOS_POR_MINUTO * (hora_inicial * MINUTOS_POR_HORA + minuto_inicial) + segundo_inicial;
   segundos_finales   = SEGUNDOS_POR_MINUTO * (hora_final * MINUTOS_POR_HORA + minuto_final) + segundo_final;
   segundos_diferencia = segundos_finales - segundos_iniciales;

   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
}

int main(){
	double limite_superior, tarifa;
	const int TERMINADOR = -1;
	int hora_inicial, minuto_inicial, segundo_inicial,
   	 hora_final, minuto_final, segundo_final,
   	 minutos_estacionamiento; 
   double tarifa_parking_1, tarifa_parking_2,
			 total_recaudado_parking_1, total_recaudado_parking_2;

	TarifadoParking parking_1, parking_2;
	
	cout << "Parking 1: \n";
	do{
		cin >> limite_superior;
		cin >> tarifa;
		parking_1.AniadeTramo(limite_superior, tarifa);
	}while (limite_superior != TERMINADOR 													// Cuando limite_superior sea -1, éste valdrá tanto de TERMINADOR
			  && parking_1.TotalUtilizados() < parking_1.Capacidad() );				// como para definir el último tramo

	cout << "\nParking 2: \n";
	do{
		cin >> limite_superior;
		cin >> tarifa;
		parking_2.AniadeTramo(limite_superior, tarifa);
	}while (limite_superior != TERMINADOR
			  && parking_2.TotalUtilizados() < parking_2.Capacidad() );

	cout << "\nIndique la hora de entrada (hh:mm:ss): ";
	cin >> hora_inicial;
   
   while (hora_inicial != TERMINADOR){     
      cin >> minuto_inicial;
      cin >> segundo_inicial;
   
      cout << "Indique la hora de salida (hh:mm:ss): ";
		cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;
      
      minutos_estacionamiento = MinutosEntreInstantes(hora_inicial, minuto_inicial, segundo_inicial,
                               								hora_final, minuto_final, segundo_final);
      
      tarifa_parking_1 = parking_1.GetTarifa(minutos_estacionamiento);
      tarifa_parking_2 = parking_2.GetTarifa(minutos_estacionamiento);
                                   
   	cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
   	total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
   	total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cout << "Indique la hora de entrada (hh:mm:ss): ";
      cin >> hora_inicial;
   }

	cout << "\n\n";
	
	system("pause");
}
