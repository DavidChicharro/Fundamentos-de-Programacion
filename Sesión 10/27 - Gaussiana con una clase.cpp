/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 10
Ejercicio 27: Gaussiana CDF con una clase

Recupere la solución del ejercicio 8 de esta relación de problemas sobre la función
gaussiana. En vez de trabajar con funciones, plantee la solución con una clase. Debe
diseñar la clase teniendo en cuenta que la función matemática gaussiana viene determinada unívocamente por 
el valor de la esperanza y la desviación, es decir, son estos
dos parámetros lo que distinguen a una función gaussiana de otra

*/
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

const double PI=3.1415927;

class GaussianaCDF{
	private:
		double esperanza,
				 desviacion,
				 x;
				 
		void SetAbscisa(double abscisa_x){
			x = abscisa_x;
		}
		
		void SetEsperanza(double valor_esperanza){
			esperanza = valor_esperanza;
		}
		
		void SetDesviacion(double valor_desviacion){
			desviacion = valor_desviacion;
		}
		
		
		
	public:
		GaussianaCDF (double abscisa_x, double valor_esperanza, double valor_desviacion){
			SetAbscisa(abscisa_x);
			SetEsperanza(valor_esperanza);
			SetDesviacion(valor_desviacion);
		}
		
		double CalculoAbscisa (double x){
			double valor_tipificado, exponente, y;

			valor_tipificado = (x - esperanza) / desviacion;
 			exponente = -0.5 * pow(valor_tipificado,2);
  			y = exp(exponente) / (desviacion * sqrt(2 * PI) );
   
   		return y;
		}
		
		double CalculoArea (double x){
			const double B0 = 0.2316419,
							 B1 = 0.319381530,
							 B2 = -0.356563782,
							 B3 = 1.781477937,
							 B4 = -1.821255978,
							 B5 = 1.330274429;
			double t, cdf;
	
			t = 1.0 / (1.0 + B0 * x);
			cdf = 1.0 - (CalculoAbscisa(x) * (B1 * t + 
																				  B2 * pow(t,2) + 
																				  B3 * pow(t,3) + 
																				  B4 * pow(t,4) + 
																				  B5 * pow(t,5) ) );
	
			return cdf;
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
		
		
};


int LeeIntMayorIgual(int minimo){
   int a_leer;
      		
   do{
  		cin >> a_leer;					
		}while(a_leer <= minimo);
		
		return a_leer;
}

double LeeDoubleMayorIgual(int minimo){
   double a_leer;
      		
   do{
  		cin >> a_leer;					
	}while(a_leer <= minimo);
		
	return a_leer;
}

void Presentacion(string titulo_menu, string opcion_1, string opcion_2){
	cout << "\n\n------------------------------\n" 
		  << titulo_menu << "\n\n"
		  << opcion_1 << "\n"
		  << opcion_2 << "\n"
		  << "\n------------------------------\n";
}



int main(){
   const char OPCION_INTRO_PARAMETROS  = 'P',
              OPCION_SALIR             = 'S',
              OPCION_INTRO_RANGO       = 'R',
              OPCION_VOLVER            = 'V';
   bool eligio_salir_ppal, eligio_salir_secundario;
	double esperanza, desviacion, x, min_x, max_x, incremento, y, area;
	GaussianaCDF gaussiana(0.0, 0.0, 0.0);
   
   cout << "GAUSSIANA";
   
   do{
   	Presentacion("Menu Principal", "Parametros", "Salir");
			   
      eligio_salir_ppal = gaussiana.MenuPrincipal(OPCION_INTRO_PARAMETROS, OPCION_SALIR); 
      
      if (! eligio_salir_ppal){
         cout << "\nIntroduzca el valor del parametro 'esperanza': ";
      	cin >> esperanza;
      	
      	cout << "Introduzca el valor de la desviacion: ";
      	desviacion = LeeIntMayorIgual(0);
         
         do{
            Presentacion("Menu Secundario", "Rango", "Volver");
				
				eligio_salir_secundario = gaussiana.MenuSecundario(OPCION_INTRO_RANGO, OPCION_VOLVER);                                        
            
            if (! eligio_salir_secundario){
               cout << "\nIntroduzca el valor minimo de la abscisa: ";
            	cin >> min_x;
            	
               cout << "Introduce el valor máximo de la abscisa: ";
               max_x = LeeDoubleMayorIgual(min_x);        
					
					cout << "Introduce los saltos de incremento de la abscisa: ";
               incremento = LeeDoubleMayorIgual(0);
               
               GaussianaCDF gaussiana(min_x, esperanza, desviacion);
					         
               x = min_x;
               
               while (x <= max_x){
               	y = gaussiana.CalculoAbscisa(x);
                  area = gaussiana.CalculoArea(x);
                  
                  cout << "\nf(" << x << ")= " << y
                  	  << "\tCDF(" << x << ")= " << area;
                  
                  x = x + incremento;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
   
   system("pause");
}
