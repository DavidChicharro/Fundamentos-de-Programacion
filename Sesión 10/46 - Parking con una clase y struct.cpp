/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 10
Ejercicio 46: Parking con una clase y struct

Recupere la solución del ejercicio 29 (Parking con una clase) 
Defina un struct llamado InstanteTiempo para almacenar la hora, minutos y segundos 
que constituyen un instante de tiempo. 
Cambie la definición de la función MinutosEntreInstantes y el programa principal 
para que trabaje con este tipo struct.

*/

#include <iostream>
using namespace std;

struct InstanteTiempo{
	int hora;
	int minutos;
	int segundos;
};

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

int MinutosEntreInstantes (InstanteTiempo primer_instante, InstanteTiempo segundo_instante){
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
   int segundos_iniciales, segundos_finales, segundos_diferencia;
   
   segundos_iniciales = SEGUNDOS_POR_MINUTO * (primer_instante.hora * MINUTOS_POR_HORA + primer_instante.minutos) + primer_instante.segundos;
   segundos_finales   = SEGUNDOS_POR_MINUTO * (segundo_instante.hora * MINUTOS_POR_HORA + segundo_instante.minutos) + segundo_instante.segundos;
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
   double tarifa_parking_1, tarifa_parking_2,
			 total_recaudado_parking_1, total_recaudado_parking_2;
   int minutos_estacionamiento;   
   InstanteTiempo primer_instante, segundo_instante;

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
   
   TarifaParking parking_1.TarifaParking(limite_tramo_1_parking_1, limite_tramo_2_parking_1, limite_tramo_3_parking_1, limite_tramo_4_parking_1, 
													  tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1, 
													  tarifa_dia_completo_parking_1);
	TarifaParking parking_2.TarifaParking(limite_tramo_1_parking_2, limite_tramo_2_parking_2, limite_tramo_3_parking_2, limite_tramo_4_parking_2, 
													  tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2, 
													  tarifa_dia_completo_parking_2);
   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;
   
   cout << "Indique la hora de entrada (hh:mm:ss): ";
	cin >> primer_instante.hora; 
   
   while (primer_instante.hora != TERMINADOR_ENTRADA_DATOS){     
      cin >> primer_instante.minutos;
      cin >> primer_instante.segundos;
   
      cout << "Indique la hora de salida (hh:mm:ss): ";
		cin >> segundo_instante.hora;
      cin >> segundo_instante.minutos;
      cin >> segundo_instante.segundos;
      
      minutos_estacionamiento = MinutosEntreInstantes(primer_instante, segundo_instante);
      
      tarifa_parking_1 = parking_1.CalculaTarifa(minutos_estacionamiento);                
      tarifa_parking_2 = parking_2.CalculaTarifa(minutos_estacionamiento);
                                   
      cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cout << "Indique la hora de entrada (hh:mm:ss): ";
      cin >> primer_instante.hora;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
        
   system("pause");
}
