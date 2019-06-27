/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 9
Ejercicio 23-g) Métodos privados
Vuelva a recuperar el método SetCoeficientes. Añada un método privado
que nos indique si los coeficientes son correctos, es decir, A y B no pueden ser
simultáneamente nulos.
*/

#include <iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0,
				 B = 0.0,
				 C = 0.0;
	
		bool SonCorrectosCoeficientes(double candidato_A, double candidato_B){
			return candidato_A != 0 && candidato_B != 0;
		}
	
	public:
		Recta(double A, double B, double C){
			SetCoeficientes(A, B, C);
		}
			
		void SetCoeficientes(double candidato_A, double candidato_B, double candidato_C){
			if (SonCorrectosCoeficientes(candidato_A, candidato_B)){
				A = candidato_A;
				B = candidato_B;
				C = candidato_C;
			}
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
	Recta recta_1(0, 0, 0),
			recta_2(0, 0, 0);
	double abscisa,
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
	
	SalidaPendiente(1, recta_1.Pendiente());
	SalidaPendiente(2, recta_2.Pendiente());
	cout << "\n\nLa ordenada de la recta 1 cuando 'x' vale " << abscisa << " es: " << recta_1.Ordenada(abscisa) << endl <<
			  "El valor de la abscisa para la ordenada: " << recta_1.Ordenada(abscisa) << " es: " << recta_1.Abscisa(recta_1.Ordenada(abscisa));
	cout << "\n\n";
	
	system ("pause");	
}
