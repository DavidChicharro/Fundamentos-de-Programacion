/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 15 - Circunferencia con centro un Punto2D

Programa que lee el centro y la longitud del radio para construir una circunferencia.
A partir de ella se construirá el segmento correspondiente al radio.
Después se calculará la longitud del segmento radio y mostrará el resultado en pantalla,
que deberá coincidir con la longitud original del radio)
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

class Punto2D{
private:
	double abscisa;
	double ordenada;

public:
	Punto2D(double abscisaPunto, double ordenadaPunto)
		:abscisa(abscisaPunto),
		 ordenada(ordenadaPunto)
	{
	}
	
	double Abscisa(){
		return abscisa;
	}
	
	double Ordenada(){
		return ordenada;
	}
};

class Circunferencia{
private:
	Punto2D centro;
	double radio;
	
public:
	Circunferencia(double centro_circunferencia_abscisa, double centro_cincunferencia_ordenada, double radio_circunferencia)
		:centro(centro_circunferencia_abscisa, centro_cincunferencia_ordenada),
		 radio(radio_circunferencia)
	{
	}
	
	double Longitud(){		
		return 2 * PI * radio;
	}
	
	double Area(){
		return PI * radio * radio;
	}
	
	void SetRadio(double radio_circunferencia){
		radio = radio_circunferencia;
	}
};

class SegmentoDirigido{
private:
	Punto2D origen;
	Punto2D final;
	
public:
	SegmentoDirigido(double centro_circunferencia_abscisa, double centro_cincunferencia_ordenada,
						  double punto_abscisa, double punto_ordenada)
		:origen(centro_circunferencia_abscisa, centro_cincunferencia_ordenada),
		 final(punto_abscisa, punto_ordenada)
	{
	}						  
	
	Punto2D Origen(){
		return origen;
	}
	
	Punto2D Final(){
		return final;
	}
	
	double Longitud(){
		double abscisas = origen.Abscisa() - final.Abscisa();
		double ordenadas = origen.Ordenada() - final.Ordenada();
		
		return sqrt ( pow(abscisas,2) + pow(ordenadas,2) );
	}
};

int main(){
	double centro_circunferencia_abscisa, centro_cincunferencia_ordenada, radio_circunferencia,
			 punto_abscisa, punto_ordenada;
	
	// Entrada de datos
	cout << "Establezca el centro de la circunferencia: " << endl;
	cin >> centro_circunferencia_abscisa;
	cin >> centro_cincunferencia_ordenada;
	cout << "Indique el radio de la circunferencia: " ;
	cin >> radio_circunferencia;
	
	Circunferencia circunferencia(centro_circunferencia_abscisa, centro_cincunferencia_ordenada, radio_circunferencia);
	
	
	cout << "Indique un punto de la circunferencia para calcular el segmento dirigido: " << endl;
	cin >> punto_abscisa;
	cin >> punto_ordenada;
	
	SegmentoDirigido segmento_dirigido(centro_circunferencia_abscisa, centro_cincunferencia_ordenada,
							 punto_abscisa, punto_ordenada);
	
	// Cómputos y salida de resultados
	cout << "A continuacion se mostrara la longitud del segmento dirigido. " << endl
		  << "Medira lo mismo que el radio si las coordenadas introducidas pertenecen a la circunferencia. " << endl
		  << segmento_dirigido.Longitud() << endl;
		  
	system ("pause");
}
