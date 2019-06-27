/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 12 - Polígono (Examen Febrero 2016)
Programa que genera un poligono regular con valores por defecto (poligono1) y otro con unos valores dados (poligono2).
Se generarán otros dos polígonos regulares a partir del primero (poligono3 y poligono4)
Se compararán las áreas del poligono1 y el poligono2.
Se duplicará el número de lados del poligono3 y se comparará su área con el poligono1.
Se duplicará el número de lados del poligono4 hasta que se asemeje a la circunferencia circunscrita (error < 1e-5)
Finalmente se mostrará en pantalla los resultados de dichas comparaciones y el numero de lados que tendrá el poligono4.
 */

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

class Punto2D{
private:
	double abscisa;
	double ordenada;
	
public:
	Punto2D(double coordenada_abscisa, double coordenada_ordenada)
		:abscisa(coordenada_abscisa),
		 ordenada(coordenada_ordenada)
	{
	}
	
	double Abscisa(){
		return abscisa;
	}
	
	double Ordenada(){
		return ordenada;
	}
};

class PoligonoRegular{
private:
	int numero_lados;
	double longitud_lados;
	double radio;
	Punto2D centro;
	
public:
	PoligonoRegular()
		:numero_lados(3),
		 longitud_lados(1),
		 centro(0, 0)
	{
		radio = longitud_lados / (2*sin(PI/numero_lados));
	}
	
	PoligonoRegular(int num_lados, double longitud)
		:numero_lados(num_lados),
		 longitud_lados(longitud),
		 centro(0,0)
	{
		radio = longitud_lados / (2*sin(PI/numero_lados));
	}
	
	PoligonoRegular(int num_lados, double longitud, double abscisa_centro, double ordenada_centro)
		:numero_lados(num_lados),
		 longitud_lados(longitud),
		 centro (abscisa_centro, ordenada_centro)
	{
		radio = longitud_lados / (2*sin(PI/numero_lados));
	}
	
	int NumeroLados(){
		return numero_lados;
	}
	
	double LongitudLados(){
		return longitud_lados;
	}
	
	void MultiplicaLados(int k){
		if (k > 1)
			numero_lados = numero_lados * k;
			longitud_lados = 2 * radio * sin(PI / numero_lados);
	}
	
	double Radio(){
		return radio;
	}
	
	double Area(){
		return (numero_lados * pow(radio,2) * sin(2*PI / numero_lados)) / 2;
	}
	
	double Perimetro(){
		return numero_lados * longitud_lados;
	}
	
	double DiferenciaAreas(){
		return (PI * pow(radio,2) ) - Area();
	}
	
	bool ComparaPoligonos(PoligonoRegular poligono){
		return Area() > poligono.Area();
	}
};

int main(){
	// Declaracion de variables
	bool mas_grande;	
	PoligonoRegular poligono1,
						 poligono2 (6, 4, 0, 0),
						 poligono3(poligono1),
						 poligono4(poligono1);
						 
	// Cómputos
	mas_grande = poligono1.ComparaPoligonos(poligono2);
	poligono3.MultiplicaLados(2);
		
	while (poligono4.DiferenciaAreas() > 1e-5)
		poligono4.MultiplicaLados(2);
	
	// Salida de resultados
	if (mas_grande)
		cout << "\nEl poligono 1 es mas grande que el poligono 2.";
	else
		cout << "\nEl poligono 2 es mas grande que el poligono 1.";
	
	cout << "\n\nEl poligono 3 tiene la misma circunferencia circunscrita que el poligono 1 y el doble numero de lados. " << endl <<
	  		  "El area del poligono 1 es: " << poligono1.Area() << ", mientras que la del poligono 3 es: " << poligono3.Area();
	
	cout << "\n\nEl poligono 4 ha generado el doble numero de lados que el poligono 1 hasta ser semejante a la circunferencia circunscrita. " << endl <<
			  "El numero de lados que aproxima a la circunferencia es: " << poligono4.NumeroLados() << " lados. \n\n";
			  
	system ("pause");
}
