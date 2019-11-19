/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 3 - Lector tarifador parking

Programa que calcula las tarifas de dos parkings utilizando 
una clase LectorTarifador que realiza la entrada de datos.
y la clase 'Instante' que devuelve como objetos los instantes 
de entrada y salida del vehículo.
Una vez introducidos los tramos horarios y las tarifas de cada tramo, 
el programa calculará la tarifa total de ambos parkings.

*/

#include <iostream>
using namespace std;

class Instante{
private:
	int instante_inicial;
	int instante_final;
	static const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;

public:
	void SetInstanteInicial (int hora_inicial, int minuto_inicial, int segundo_inicial){
		instante_inicial = SEGUNDOS_POR_MINUTO * (hora_inicial * MINUTOS_POR_HORA + minuto_inicial) + segundo_inicial;
	}
	
	void SetInstanteFinal (int hora_final, int minuto_final, int segundo_final){
		instante_final = SEGUNDOS_POR_MINUTO * (hora_final * MINUTOS_POR_HORA + minuto_final) + segundo_final;
	}
	
	int InstanteInicial(){
		return instante_inicial;
	}
	
	int InstanteFinal(){
		return instante_final;
	}
	
	int Diferencia(){
		int diferencia = instante_final - instante_inicial;
		
		return diferencia / SEGUNDOS_POR_MINUTO;
	}
};

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
	
	void SetTramo(double tramo){
		vector_tramos[total_utilizados] = tramo;
	}

	void SetTarifa(double tarifa){
		vector_tarifas[total_utilizados] = tarifa;
	}
	
	void AniadeTramo (double limite_superior_tramo, double tarifa_tramo){
		vector_tramos[total_utilizados] = limite_superior_tramo;
		vector_tarifas[total_utilizados] = tarifa_tramo;
		total_utilizados++;		
	}
	
	double GetTarifa(Instante minutos_estacionamiento){
		bool tiempo_limite_rebasado;
		bool continuar = true;
		double vector_minutos_tramo[TAMANIO] = {0};
		double tarifa = 0;
		
		tiempo_limite_rebasado = (minutos_estacionamiento.Diferencia() > vector_tramos[total_utilizados - 2]);
		vector_tramos[-1] = 0;
		
		for (int i = 0 ; i < total_utilizados - 1 && !tiempo_limite_rebasado && continuar ; i++){
			if (minutos_estacionamiento.Diferencia() < vector_tramos[i]){
				vector_minutos_tramo[i] = minutos_estacionamiento.Diferencia() - vector_tramos[i-1];
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

class LectorTarifador{
private:
	static const int TERMINADOR = -1;
	
public:	
	TarifadoParking LeeTarifador_TarifaDiaCompletoUltimoDato(){
		double limite_superior, tarifa;
		TarifadoParking tarifador_parking;
		
		do{
			cin >> limite_superior;
			cin >> tarifa;
			tarifador_parking.AniadeTramo(limite_superior, tarifa);			
			
		}while (limite_superior != TERMINADOR
				  && tarifador_parking.TotalUtilizados() < tarifador_parking.Capacidad() );
				  
		return tarifador_parking;
	}
};

int main(){
	const int TERMINADOR = -1;
	int hora_inicial, minuto_inicial, segundo_inicial,
   	 hora_final, minuto_final, segundo_final;
   double tarifa_parking_1, tarifa_parking_2,
			 total_recaudado_parking_1 = 0, total_recaudado_parking_2 = 0;
	TarifadoParking tarifa_1, tarifa_2;
	Instante instante;
	LectorTarifador tarifador_parking_1, tarifador_parking_2;
	
	cout << "Parking 1: \n";
	tarifa_1 = tarifador_parking_1.LeeTarifador_TarifaDiaCompletoUltimoDato();

	cout << "\nParking 2: \n";
	tarifa_2 = tarifador_parking_2.LeeTarifador_TarifaDiaCompletoUltimoDato();

	cout << "\nIndique la hora de entrada (hh:mm:ss): ";
	cin >> hora_inicial;
   
   while (hora_inicial != TERMINADOR){     
      cin >> minuto_inicial;
      cin >> segundo_inicial;
   
      cout << "Indique la hora de salida (hh:mm:ss): ";
		cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;
                               								
      instante.SetInstanteInicial(hora_inicial, minuto_inicial, segundo_inicial);
      instante.SetInstanteFinal(hora_final, minuto_final, segundo_final);
      
      tarifa_parking_1 = tarifa_1.GetTarifa(instante);
      tarifa_parking_2 = tarifa_2.GetTarifa(instante);
                                   
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
