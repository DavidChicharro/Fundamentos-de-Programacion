/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 9
Ejercicio 23-b) M�todos p�blicos

En la funci�n main se leer� un valor de abscisa.
La pendiente ser� calculada mediante un m�todo.
	 Obtener la ordenada (y) dado un valor de abscisa x
	 Obtener la abscisa (x) dado un valor de ordenada y
Esto se har� s�lo con la primera recta.
*/

#include <iostream>

using namespace std;

class Recta{
	public:
		double A, B, C;
					
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
			 abscisa, ordenada_1, abscisa_1;
	
	cout << "La ecuacion general de la recta es: Ax + By + C = 0 \n";
	
	Titulo(1);
	cin >> recta_1.A;
	cin >> recta_1.B;
	cin >> recta_1.C;
	
	Titulo(2);
	cin >> recta_2.A;
	cin >> recta_2.B;
	cin >> recta_2.C;
	
	cout << "Introduzca un valor de abscisa (x): ";
	cin >> abscisa;
	
	pendiente_1 = recta_1.Pendiente(recta_1.A, recta_1.B);
	pendiente_2 = recta_2.Pendiente(recta_2.A, recta_2.B);
	ordenada_1 = recta_1.Ordenada(recta_1.A, recta_1.B, recta_1.C, abscisa);
	abscisa_1 = recta_1.Abscisa(recta_1.A, recta_1.B, recta_1.C, ordenada_1);
	
	SalidaPendiente(1, pendiente_1);
	SalidaPendiente(2, pendiente_2);
	cout << "\n\nLa ordenada de la recta 1 cuando 'x' vale " << abscisa << " es: " << ordenada_1 << endl <<
			  "El valor de la abscisa para la ordenada: " << ordenada_1 << " es: " << abscisa_1;
	cout << "\n\n";
	
	system ("pause");	
}
