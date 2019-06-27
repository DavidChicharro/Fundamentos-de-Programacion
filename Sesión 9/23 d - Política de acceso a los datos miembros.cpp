/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 9
Ejercicio 23-d) Política de acceso a los datos miembros

Se define un único método SetCoeficientes para asignar los tres coeficientes a la misma vez.
*/

#include <iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0,
				 B = 0.0,
				 C = 0.0;	
	
	public:
		void SetCoeficientes(double candidato_A, double candidato_B, double candidato_C){
			A = candidato_A;
			B = candidato_B;
			C = candidato_C;
		}
		
		double Coeficiente_A(){
			return A;
		}
		
		double Coeficiente_B(){
			return B;
		}
		
		double Coeficiente_C(){
			return C;
		}
						
		double Pendiente(){
			double pendiente;
	
			pendiente = -A / B;
			return pendiente;
		}
		
		double Ordenada(double x){
			double ordenada;
			
			ordenada = (-C - x * A) / B;			
			return ordenada;
		}
		
		double Abscisa(double y){
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
	
	recta_1.SetCoeficientes(A_1, B_1, C_1);
	recta_2.SetCoeficientes(A_2, B_2, C_2);
	
	pendiente_1 = recta_1.Pendiente();
	pendiente_2 = recta_2.Pendiente();
	ordenada_1 = recta_1.Ordenada(abscisa);
	abscisa_1 = recta_1.Abscisa(ordenada_1);
	
	SalidaPendiente(1, pendiente_1);
	SalidaPendiente(2, pendiente_2);
	cout << "\n\nLa ordenada de la recta 1 cuando 'x' vale " << abscisa << " es: " << ordenada_1 << endl <<
			  "El valor de la abscisa para la ordenada: " << ordenada_1 << " es: " << abscisa_1;
	cout << "\n\n";
	
	system ("pause");	
}
