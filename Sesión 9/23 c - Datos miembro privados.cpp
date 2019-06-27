/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 9
Ejercicio 23-c) Datos miembro privados

Cambie ahora los datos miembro públicos y póngalos privados. 
Tendrá que añadir métodos para asignar y ver los valores de los datos miembro. 
Añada métodos para asignar un valor a cada uno de los tres datos miembro. 

*/

#include <iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0,
				 B = 0.0,
				 C = 0.0;
	
	
	public:
		void SetPuntos(double candidato_A, double candidato_B, double candidato_C){
			A = candidato_A;
			B = candidato_B;
			C = candidato_C;
		}
		
		double Punto_A(){
			return A;
		}
		
		double Punto_B(){
			return B;
		}
		
		double Punto_C(){
			return C;
		}
						
		double Pendiente(double A, double B){
			double pendiente;
	
			pendiente = -A / B;
			return pendiente;
		}
		
		double Ordenada(double A, double B, double C, double x){
			double ordenada;
			
			ordenada = (-C - x * A) / B;			
			return ordenada;
		}
		
		double Abscisa(double A, double B, double C, double y){
			double abscisa;
			
			abscisa = (-C - y * B) / A;
			return abscisa;
		}
};

void Titulo(int numero){
	cout << "\nRecta " << numero << ": \n";
	cout << "Introduzca los coeficientes de la recta: ";
}

void SalidaPendiente(int numero, double pendiente){	
	cout << "\nLa pendiente de la recta " << numero << " es: " << pendiente;
}

int main(){
	Recta recta_1, recta_2;
	double pendiente_1, pendiente_2,
			 abscisa, ordenada_1, abscisa_1,
			 A_1, B_1, C_1, A_2, B_2, C_2;
	
	cout << "La ecuacion general de la recta es: Ax + By + C = 0 \n";
	
	Titulo(1);
	cin >> A_1;
	cin >> B_1;
	cin >> C_1;
	
	Titulo(2);
	cin >> A_2;
	cin >> B_2;
	cin >> C_2;
	
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> abscisa;
	
	pendiente_1 = recta_1.Pendiente(A_1, B_1);
	pendiente_2 = recta_2.Pendiente(A_2, B_2);
	ordenada_1 = recta_1.Ordenada(A_1, B_1, C_1, abscisa);
	abscisa_1 = recta_1.Abscisa(A_1, B_1, C_1, ordenada_1);
	
	SalidaPendiente(1, pendiente_1);
	SalidaPendiente(2, pendiente_2);
	cout << "\n\nLa ordenada de la recta 1 cuando 'x' vale " << abscisa << " es: " << ordenada_1 << endl <<
			  "El valor de la abscisa para la ordenada: " << ordenada_1 << " es: " << abscisa_1;
	cout << "\n\n";
	
	system ("pause");	
}
