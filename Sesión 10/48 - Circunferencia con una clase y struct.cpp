/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 10
Ejercicio 48: Circunferencia con una clase y struct

48. Recupere la definición del registro CoordenadasPunto2D del ejercicio 47 de esta
relación de problemas y la solución al ejercicio 3 (Circunferencia) de la relación de
problemas I.

Cree ahora una clase llamada Circunferencia. Para establecer el centro, se usará un dato miembro 
que ha de ser de tipo CoordenadasPunto2D.
Añada métodos para obtener la longitud de la circunferencia y el área del círculo interior.

Añada también un método para saber si la circunferencia contiene a un punto cualquiera. 
Recordemos que un punto (x1, y1) está dentro de una circunferencia con centro (x0, y0) 
y radio r si se verifica que:
	(x0 - x1) 2 + (y0 - y1) 2 <= r2
	
Observe que el valor de PI debe ser constante, y el mismo para todos los objetos de
la clase Circunferencia.

Cree un programa principal que lea el centro y el radio de una circunferencia, las
coordenadas de un punto y muestre en pantalla la longitud de la circunferencia, el
área del círculo y nos diga si el punto está dentro o no de la circunferencia.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

struct Punto2D{
	double abscisa;
	double ordenada;	
};

class Circunferencia{
	private:
		Punto2D centro, punto;
		double radio;
	
	public:
		Circunferencia(double centro_x, double centro_y, double radio_circunferencia, double punto_x, double punto_y){
			SetCentro(centro_x, centro_y);
			SetRadio(radio_circunferencia);
			SetPuntoEnCircunferencia(punto_x, punto_y);
		}
		
		double Longitud(){
			double longitud;
			
			return longitud = 2 * PI * radio;
		}
		
		double Area(){
			double area;
			
			return area = PI * radio * radio;
		}
		
		Punto2D SetCentro(double centro_x, double centro_y){
			centro.abscisa = centro_x;
			centro.ordenada = centro_y;
		}
		
		void SetRadio(double radio_circunferencia){
			radio = radio_circunferencia;
		}
		
		Punto2D SetPuntoEnCircunferencia(double abscisa, double ordenada){
			punto.abscisa = abscisa;
			punto.ordenada = ordenada;
		}
			
		bool ContienePunto(){
			double resta_abscisas, resta_ordenadas, izda, dcha;
			
			resta_abscisas = centro.abscisa - punto.abscisa;
			resta_ordenadas = centro.ordenada - punto.ordenada;
			izda = pow(resta_abscisas, 2) + pow(resta_ordenadas, 2);
			dcha = pow(radio, 2);
			
			return  izda <= dcha;			
		}
};


int main(){
	double centro_x, centro_y, punto_x, punto_y, radio;
	
	cout << "Introduzca las coordenadas del centro de la circunferencia 'x' e 'y': \n";
	cin >> centro_x;
	cin >> centro_y;
	
	cout << "Introduzca el radio de la circunferencia: ";
	cin >> radio;
	
	cout << "Introduzca un punto para comprobar si pertenece a la circunferencia (x , y)\n";
	cin >> punto_x;
	cin >> punto_y;

	Circunferencia circunferencia(centro_x, centro_y, radio, punto_x, punto_y);
	
	cout << "\nLa longitud de la circunferencia es: " << circunferencia.Longitud() << endl <<
			  "El area de la circunferencia es: " << circunferencia.Area();
			  
	if (circunferencia.ContienePunto())
		cout << "\nEl punto esta dentro\n\n";
	else
		cout << "\nEl punto no esta dentro\n\n";
	
	system("pause");
}
