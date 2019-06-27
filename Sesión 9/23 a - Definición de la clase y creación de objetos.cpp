/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 9
Ejercicio 23-a) Definición de la clase y creación de objetos

Se desea implementar una clase Recta para representar una recta en el plano.
Ax + By + C = 0

Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos.
Cree un programa principal que haga lo siguiente:
	 Defina dos objetos de la clase Recta.
	 Lea seis reales desde teclado.
	 Asigne los tres primeros a los coeficientes de una recta y los otros tres a la segunda recta.
	 Calcule e imprima la pendiente de cada recta aplicando la fórmula:  pendiente = - A / B
*/

#include <iostream>
using namespace std;

class Recta{
	public:
		double A, B, C;
};

void Titulo(int numero){
	cout << "\nRecta " << numero << ": \n";
	cout << "Introduzca los coeficientes de la recta: ";
}

double Pendiente(double A, double B){;
	double pendiente;
	
	pendiente = -A / B;
	return pendiente;
}

void Salida(int numero, double pendiente){	
	cout << "\nLa pendiente de la recta " << numero << " es: " << pendiente;
}

int main(){
	Recta recta_1, recta_2;
	double pendiente_1, pendiente_2;
	
	cout << "La ecuacion general de la recta es: Ax + By + C = 0 \n";
	
	Titulo (1);
	cin >> recta_1.A;
	cin >> recta_1.B;
	cin >> recta_1.C;
	
	Titulo (2);
	cin >> recta_2.A;
	cin >> recta_2.B;
	cin >> recta_2.C;
	
	pendiente_1 = Pendiente(recta_1.A, recta_1.B);
	pendiente_2 = Pendiente(recta_2.A, recta_2.B);
	
	Salida(1, pendiente_1);
	Salida(2, pendiente_2);
	cout << "\n\n";
	
	system ("pause");	
}
