/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión
Ejercicio 29: Parking con una clase

Recupere la solución del ejercicio 10 de esta relación de problemas (población con funciones). 
Re-escríbalo para que los cómputos relacionados con la población estén encapsulados en una clase. 
La lectura de los valores en los rangos adecuados se hará con las mismas funciones que ya se definieron 
en ese ejercicio. 
Modifique apropiadamente el programa principal

*/
#include <iostream>
using namespace std;

class TarifaParking{
private:
	int limite_tramo_1, limite_tramo_2, limite_tramo_3, limite_tramo_4;
	double tarifa_tramo_1, tarifa_tramo_2, tarifa_tramo_3, tarifa_tramo_4, tarifa_dia_completo;		
		
public:
	TarifaParking(int limite_primer_tramo, int limite_segundo_tramo, int limite_tercer_tramo, int limite_cuarto_tramo,
           		  double tarifa_primer_tramo, double tarifa_segundo_tramo, double tarifa_tercer_tramo, double tarifa_cuarto_tramo, 
					  double tarifa_todo_el_dia){
		limite_tramo_1 = limite_primer_tramo;
		limite_tramo_2 = limite_segundo_tramo; 
		limite_tramo_3 = limite_tercer_tramo; 
		limite_tramo_4 = limite_cuarto_tramo;
		tarifa_tramo_1 = tarifa_primer_tramo; 
		tarifa_tramo_2 = tarifa_segundo_tramo; 
		tarifa_tramo_3 = tarifa_tercer_tramo; 
		tarifa_tramo_4 = tarifa_cuarto_tramo;
		tarifa_dia_completo = tarifa_todo_el_dia;
	}	

	double CalculaTarifa(int minutos_estacionamiento){                  
		int minutos_tramo_1, minutos_tramo_2, minutos_tramo_3, minutos_tramo_4;
		double tarifa;
		bool tiempo_limite_rebasado;

		minutos_tramo_1 = 0;
	   minutos_tramo_2 = 0;
	   minutos_tramo_3 = 0;
	   minutos_tramo_4 = 0;

		tiempo_limite_rebasado  = (minutos_estacionamiento > limite_tramo_4);

	   if (!tiempo_limite_rebasado){
	      if (minutos_estacionamiento < limite_tramo_1)
	        minutos_tramo_1 = minutos_estacionamiento;
	     else{
	        minutos_tramo_1 = limite_tramo_1;

	        if (minutos_estacionamiento < limite_tramo_2)
	           minutos_tramo_2 = minutos_estacionamiento - limite_tramo_1;
	        else{
	           minutos_tramo_2 = limite_tramo_2 - limite_tramo_1;

	            if (minutos_estacionamiento < limite_tramo_3)
   		         minutos_tramo_3 = minutos_estacionamiento - limite_tramo_2;
         		else{
	               minutos_tramo_3 = limite_tramo_3 - limite_tramo_2;
		            minutos_tramo_4 = minutos_estacionamiento - limite_tramo_3;
         		}
   		   }
	      }
		}

	   if (tiempo_limite_rebasado)
   		tarifa = tarifa_dia_completo;
		else
   		tarifa = minutos_tramo_1 * tarifa_tramo_1
            		+
            		minutos_tramo_2 * tarifa_tramo_2
            		+
            		minutos_tramo_3 * tarifa_tramo_3
            		+
            		minutos_tramo_4 * tarifa_tramo_4;

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
   const int TERMINADOR_ENTRADA_DATOS = -1;
   int limite_tramo_1_parking_1, limite_tramo_2_parking_1, 
       limite_tramo_3_parking_1, limite_tramo_4_parking_1,
       limite_tramo_1_parking_2, limite_tramo_2_parking_2, 
       limite_tramo_3_parking_2, limite_tramo_4_parking_2;
       
   double tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, 
          tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
          tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, 
          tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2;
          
   double tarifa_dia_completo_parking_1, tarifa_dia_completo_parking_2;
   double tarifa_parking_1, tarifa_parking_2;
   double total_recaudado_parking_1, total_recaudado_parking_2;
   
   int hora_inicial, minuto_inicial, segundo_inicial;
   int hora_final, minuto_final, segundo_final;
   int minutos_estacionamiento;   
 //  TarifaParking parking_1, parking_2;

   cout << "Parking\n\n";
   cout << "Limite tramo 1 parking 1: ";
   cin >> limite_tramo_1_parking_1;
   cout << "Limite tramo 2 parking 1: ";
   cin >> limite_tramo_2_parking_1;
   cout << "Limite tramo 3 parking 2: ";
   cin >> limite_tramo_3_parking_1;
   cout << "Limite tramo 4 parking 1: ";
   cin >> limite_tramo_4_parking_1;
	cout << "Tarifa tramo 1 parking 2: ";  
   cin >> tarifa_tramo_1_parking_1;
   cout << "Tarifa tramo 2 parking 1: ";
   cin >> tarifa_tramo_2_parking_1;
   cout << "Tarifa tramo 3 parking 1: ";
   cin >> tarifa_tramo_3_parking_1;
   cout << "Tarifa tramo 4 parking 1: ";
   cin >> tarifa_tramo_4_parking_1;
   cout << "Tarifa dia completo parking 1: ";
   cin >> tarifa_dia_completo_parking_1;
   cout << "Limite tramo 1 parking 2: ";
   cin >> limite_tramo_1_parking_2;
   cout << "Limite tramo 2 parking 2: ";
   cin >> limite_tramo_2_parking_2;
   cout << "Limite tramo 3 parking 2: ";
   cin >> limite_tramo_3_parking_2;
   cout << "Limite tramo 4 parking 2: ";
   cin >> limite_tramo_4_parking_2;
   cout << "Tarifa tramo 1 parking 2: ";
   cin >> tarifa_tramo_1_parking_2;
   cout << "Tarifa tramo 2 parking 2: ";
   cin >> tarifa_tramo_2_parking_2;
   cout << "Tarifa tramo 3 parking 2: ";
   cin >> tarifa_tramo_3_parking_2;
   cout << "Tarifa tramo 4 parking 2: ";
   cin >> tarifa_tramo_4_parking_2;
   cout << "Tarifa dia completo parking 2: ";
   cin >> tarifa_dia_completo_parking_2;
   
   TarifaParking parking_1(limite_tramo_1_parking_1, limite_tramo_2_parking_1, limite_tramo_3_parking_1, limite_tramo_4_parking_1, 
													  tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1, 
													  tarifa_dia_completo_parking_1);
	TarifaParking parking_2(limite_tramo_1_parking_2, limite_tramo_2_parking_2, limite_tramo_3_parking_2, limite_tramo_4_parking_2, 
													  tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2, 
													  tarifa_dia_completo_parking_2);
   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;
   
   cout << "Indique la hora de entrada (hh:mm:ss): ";
	cin >> hora_inicial;
   
   while (hora_inicial != TERMINADOR_ENTRADA_DATOS){     
      cin >> minuto_inicial;
      cin >> segundo_inicial;
   
      cout << "Indique la hora de salida (hh:mm:ss): ";
		cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;
      
      minutos_estacionamiento = MinutosEntreInstantes(hora_inicial, minuto_inicial, segundo_inicial,
                               								hora_final, minuto_final, segundo_final);
      
      tarifa_parking_1 = parking_1.CalculaTarifa(minutos_estacionamiento);                
      tarifa_parking_2 = parking_2.CalculaTarifa(minutos_estacionamiento);
                                   
      cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cout << "Indique la hora de entrada (hh:mm:ss): ";
      cin >> hora_inicial;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
        
   system("pause");
}
