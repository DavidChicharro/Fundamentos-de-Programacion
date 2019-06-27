/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 10
Ejercicio 47: Distancia Euclídea con struct

47. DeDefina un struct llamado CoordenadasPunto2D 
para representar un par de valores reales correspondientes a un punto en R2.

Defina una función DistanciaEuclidea 
para que calcule la distancia entre dos puntos cualesquiera. 

Cree un programa principal que vaya leyendo 4 valores reales desde teclado 
representando las coordenadas de dos puntos y calcule la distancia euclídea entre ellos. 

Cada vez que se lean los cuatro valores se le preguntará al usuario 
si quiere seguir introduciendo datos o no (con las opciones 's' /'n')


*/

#include <iostream>
#include <cmath>
using namespace std;

struct CoordenadasPunto2D{
	double abscisa;
	double ordenada;	
};

double DistanciaEuclidea(CoordenadasPunto2D punto_1, CoordenadasPunto2D punto_2){
	double resta_abscisas, resta_ordenadas;
	
	resta_abscisas = punto_2.abscisa - punto_1.abscisa;
	resta_ordenadas = punto_2.ordenada - punto_1.ordenada;
	
	return sqrt(resta_abscisas * resta_abscisas + resta_ordenadas * resta_ordenadas);	
}

int main(){
	CoordenadasPunto2D punto_1, punto_2;
	bool seguir_leyendo_datos = true,
		  caracter_valido;
	char opcion_continuar;

	while(seguir_leyendo_datos){

		cout << "\nPunto 1\n";
		cout << "Introduzca el valor de la coordenada 'x': ";
		cin >> punto_1.abscisa;
		cout << "Introduzca el valor de la ordenada 'y': ";
		cin >> punto_1.ordenada;
	
		cout << "Punto 2\n";
		cout << "Introduzca el valor de la coordenada 'x': ";
		cin >> punto_2.abscisa;
		cout << "Introduzca el valor de la ordenada 'y': ";
		cin >> punto_2.ordenada;
	
		cout << "\nLa distancia entre los dos puntos es: " << DistanciaEuclidea(punto_1, punto_2) << "\n\n";
	
		cout << "¿Desea continuar leyendo datos?" << endl <<
				  "Introduzca 'S' para Si, o 'N' para No\n";
	
		do{
			cin >> opcion_continuar;
		
			opcion_continuar = toupper(opcion_continuar);
		
			if (opcion_continuar == 'S' || opcion_continuar == 'N')
				caracter_valido = true;		
		
		}while(! caracter_valido);
	
		if (opcion_continuar == 'N')
			seguir_leyendo_datos = false;		
	}
	
	system("pause");
}
