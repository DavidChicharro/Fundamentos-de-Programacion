/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 8
Ejercicio 8: Gaussiana CDF

Primero se definen los par�metros de la funci�n, y el programa calcular� 
el valor de 'y' seg�n los valores y tramos de 'x' previamente definidos.
El programa adem�s dispondr� de dos men�s que permitir�n realizar diferentes acciones.
El programa tambi�n calcular� el �rea que cubre la funci�n gaussiana en el intervalo [-inf, x]
Finalmente los valores de 'y' y el �rea se imprimir�n en pantalla en funci�n de 'x'.

*/

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

void Presentacion(string titulo_menu, string opcion_1, string opcion_2){
	cout << "\n\n------------------------------\n" 
		  << titulo_menu << "\n\n"
		  << opcion_1 << "\n"
		  << opcion_2 << "\n"
		  << "\n------------------------------\n";
}

int LeeIntMayorIgual(int minimo, string mensaje){
   int a_leer;
      		
   do{
      cout << "Introduzca el valor de la " << mensaje << ". "
      	  << "Debe ser un numero positivo. ";
  		cin >> a_leer;					
		}while(a_leer <= minimo);
		
		return a_leer;
}

double LeeDoubleMayorIgual(int minimo, string mensaje){
   double a_leer;
      		
   do{
      cout << mensaje
      	  << "Debe ser un numero positivo. ";
  		cin >> a_leer;					
	}while(a_leer <= minimo);
		
	return a_leer;
}

bool MenuPrincipal (char opcion_intro_parametros, char opcion_salir){
	char opcion_menu_ppal;
	bool eligio_salir_ppal, correcta_opcion_ppal;
		
   do{
      cout << "\nIntroduzca la opcion (" << opcion_intro_parametros << "/" << opcion_salir << ") ";
      cin >> opcion_menu_ppal;
      opcion_menu_ppal = toupper(opcion_menu_ppal);
      eligio_salir_ppal = opcion_menu_ppal == opcion_salir;
      correcta_opcion_ppal = eligio_salir_ppal ||
                             opcion_menu_ppal == opcion_intro_parametros;
   }while (! correcta_opcion_ppal);
		
	return eligio_salir_ppal;
}

bool MenuSecundario (char opcion_intro_rango, char opcion_volver){
	char opcion_menu_secundario;
	bool eligio_salir_secundario, correcta_opcion_secundario;
		
   do{
      cout << "\nIntroduzca la opcion (" << opcion_intro_rango << "/" << opcion_volver << ") ";
      cin >> opcion_menu_secundario;
      opcion_menu_secundario = toupper(opcion_menu_secundario);
      eligio_salir_secundario = opcion_menu_secundario == opcion_volver;
      correcta_opcion_secundario = eligio_salir_secundario ||
                             		  opcion_menu_secundario == opcion_intro_rango;
   }while (! correcta_opcion_secundario);
		
	return eligio_salir_secundario;
}

double Gaussiana (double x, double esperanza, double desviacion){
	double valor_tipificado, exponente, y;
	const double PI = 3.1415927;
	
	valor_tipificado = (x - esperanza) / desviacion;
   exponente = -0.5 * pow(valor_tipificado,2);
   y = exp(exponente) / (desviacion * sqrt(2 * PI) );
   
   return y;
}

double Potencia (double t, int exponente){
	double potencia = 1.0;
      
	for (int i = 1 ; i <= exponente ; i++)
		potencia = t * potencia;
		
	return potencia;
}

double CDF (double x, double esperanza, double desviacion){
	const double B0 = 0.2316419,
					 B1 = 0.319381530,
					 B2 = -0.356563782,
					 B3 = 1.781477937,
					 B4 = -1.821255978,
					 B5 = 1.330274429;
	double t, cdf;
	
	t = 1.0 / (1.0 + B0 * x);
	cdf = 1.0 - ( Gaussiana(x, esperanza, desviacion) * (B1 * t + 
																		  B2 * Potencia(t,2) + 
																		  B3 * Potencia(t,3) + 
																		  B4 * Potencia(t,4) + 
																		  B5 * Potencia(t,5) ) );
	
	return cdf;
}

int main(){
   const char OPCION_INTRO_PARAMETROS  = 'P',
              OPCION_SALIR             = 'S',
              OPCION_INTRO_RANGO       = 'R',
              OPCION_VOLVER            = 'V';
   bool eligio_salir_ppal, eligio_salir_secundario;
	double esperanza, desviacion, x, min_x, max_x, incremento, y, area;
	string mensaje_maximo = "Introduzca el valor maximo de la abscisa. ",
			 mensaje_incremento = "Introduzca el valor del incremento. ";
   
   cout << "GAUSSIANA";
   
   do{
   	Presentacion("Menu Principal", "Parametros", "Salir");
			   
      eligio_salir_ppal = MenuPrincipal(OPCION_INTRO_PARAMETROS, OPCION_SALIR); 
      
      if (! eligio_salir_ppal){
         cout << "\nIntroduzca el valor del parametro 'esperanza': ";
      	cin >> esperanza;
      
      	desviacion = LeeIntMayorIgual(0, "desviacion");
         
         do{
            Presentacion("Menu Secundario", "Rango", "Volver");
				
				eligio_salir_secundario = MenuSecundario(OPCION_INTRO_RANGO, OPCION_VOLVER);                                        
            
            if (! eligio_salir_secundario){
               cout << "\nIntroduzca el valor minimo de la abscisa: ";
            	cin >> min_x;
               
               max_x = LeeDoubleMayorIgual(min_x, mensaje_maximo);          
               incremento = LeeDoubleMayorIgual(0, mensaje_incremento);            
               x = min_x;
               
               while (x <= max_x){
                  y = Gaussiana(x, esperanza, desviacion);
                  area = CDF(x, esperanza, desviacion);
                  
                  cout << "\nf(" << x << ")= " << y
                  	  << "\tCDF(" << x << ")= " << area;
                  
                  x = x + incremento;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}
