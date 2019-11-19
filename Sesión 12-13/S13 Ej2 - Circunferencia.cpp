/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 2 - Circunferencia

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
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto){
		abscisa = abscisaPunto;
		ordenada = ordenadaPunto;
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
	double Longitud(){		
		return 2 * PI * radio;
	}
	
	double Area(){
		return PI * radio * radio;
	}
	
	void SetCentro(double centro_x, double centro_y){
		centro.SetCoordenadas(centro_x, centro_y);
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
	void SetCoordenadas (double origen_abscisa, double origen_ordenada,
								double final_abscisa, double final_ordenada){
		origen.SetCoordenadas(origen_abscisa, origen_ordenada);
		final.SetCoordenadas(final_abscisa, final_ordenada);
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
	Circunferencia circunferencia;
	SegmentoDirigido segmento_dirigido;
	
	// Entrada de datos
	cout << "Establezca el centro de la circunferencia: " << endl;
	cin >> centro_circunferencia_abscisa;
	cin >> centro_cincunferencia_ordenada;
	cout << "Indique el radio de la circunferencia: " ;
	cin >> radio_circunferencia;
	
	circunferencia.SetCentro(centro_circunferencia_abscisa, centro_cincunferencia_ordenada);
	circunferencia.SetRadio(radio_circunferencia);
	
	cout << "Indique un punto de la circunferencia para calcular el segmento dirigido: " << endl;
	cin >> punto_abscisa;
	cin >> punto_ordenada;
	
	// Cómputos
	segmento_dirigido.SetCoordenadas (centro_circunferencia_abscisa, centro_cincunferencia_ordenada,
							 punto_abscisa, punto_ordenada);
	
	// Salida de resultados
	cout << "A continuacion se mostrara la longitud del segmento dirigido. " << endl
		  << "Medira lo mismo que el radio si las coordenadas introducidas pertenecen a la circunferencia. " << endl
		  << segmento_dirigido.Longitud() << endl ;
		  
	system ("pause");
}
