/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 9
Ejercicio 23-f) Política de acceso a los datos miembro

Suprima ahora el método SetCoeficientes.
Una vez creado el objeto (pasándole los datos apropiados en el constructor) 
ya no podremos modificar los datos miembro. 
Esto es útil en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.

*/

#include <iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0,
				 B = 0.0,
				 C = 0.0;	
	
	public:
		Recta(double candidato_A, double candidato_B, double candidato_C){
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

void SalidaPendiente(int numero, double pendiente){	
	cout << "\nLa pendiente de la recta " << numero << " es: " << pendiente;
}

int main(){
	Recta recta_1(-3, -2, 6),
			recta_2(2, -1, 5);
	double abscisa;
	
	cout << "La ecuacion general de la recta es: Ax + By + C = 0 \n";
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> abscisa;
	
	cout << "\nLa pendiente de la recta 1 es: " << recta_1.Pendiente();
	cout << "\nLa pendiente de la recta 1 es: " << recta_2.Pendiente();
	cout << "\n\nLa ordenada de la recta 1 cuando 'x' vale " << abscisa << " es: " << recta_1.Ordenada(abscisa) << endl <<
			  "El valor de la abscisa para la ordenada: " << recta_1.Ordenada(abscisa) << " es: " << recta_1.Abscisa(recta_1.Ordenada(abscisa));
	cout << "\n\n";
	
	system ("pause");	
}
