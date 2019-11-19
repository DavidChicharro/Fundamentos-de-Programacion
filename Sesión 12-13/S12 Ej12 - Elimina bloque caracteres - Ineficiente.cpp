/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 12
Ejercicio 12 - Elimina un bloque de caracteres. Versión ineficiente

Sobre la clase SecuenciaCaracteres, añada el método EliminaBloque 
para que borre todos los caracteres que haya entre dos posiciones.

Un primer algoritmo (poco eficiente) para resolver este problema sería el siguiente:
Para borrar el bloque entre izda y dcha:
	Recorrer cada componente -i- de la secuencia
	entre las posiciones izda y dcha
		Eliminar dicha componente -i

El programa que leerá caracteres hasta el terminador '#'. 
A continuación se leerán dos enteros que representen las posiciones 
izquierda y derecha del bloque a borrar. Una vez borrados los caracteres,
se imprimirá en pantalla la secuencia resultante de quitar dicho bloque.

*/

#include <iostream>
#include <string>
using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 100;
	char vector_privado[TAMANIO];
	int total_utilizados;
	
public:
	SecuenciaCaracteres()
		:total_utilizados(0){
	}
	
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	int Capacidad(){
		return TAMANIO;
	}
	
	char GetVector(int posicion){
		return vector_privado[posicion];
	}
	
	int PosicionMinimo(){
		char minimo = vector_privado[0];
		int posicion_minimo = 0;
		
		for (int i = 1 ; i < total_utilizados ; i++){
			if (vector_privado[i] < minimo){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
			else
				posicion_minimo = -1;
		}
		
		return posicion_minimo;
	}				
	
	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	void Elimina(int posicion){
		if (posicion >= 0 && posicion < total_utilizados){
			int tope = total_utilizados - 1;
			
			for (int i = posicion ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];
				
			total_utilizados--;
		}
	}
	
	void EliminaOcurrenciasERROR(char a_borrar){
		for (int i = 0 ; i < total_utilizados; i++)
			while (vector_privado[i] == a_borrar)
				Elimina(i);
	}
	
	void EliminaBloque(int izda, int dcha){
		for (int i = dcha ; izda <= i ; i--)
			Elimina(izda);
	}
	
	void EliminaMinimo(){
		Elimina( PosicionMinimo() );
	}
	
	void EliminaUltimo(){
		total_utilizados++;
	}
	
	void EliminaTodos(){
		total_utilizados = 0;
	}
	
	void Trunca(int nuevo_total){
		if (0 <= nuevo_total && nuevo_total < total_utilizados)
			total_utilizados = nuevo_total;
	}
	
	void Modifica(int posicion, char nuevo){
		if (posicion >= 0 && posicion < total_utilizados)
			vector_privado[posicion] = nuevo;
	}
		
	char Elemento(int indice){
		return vector_privado[indice];
	}
	
	int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
		bool encontrado = false;
		int posicion;
		
		for (int i = pos_izda ; i <= pos_dcha && !encontrado ; i++)
			if (vector_privado[i] == buscado){
				encontrado = true;
				posicion = i;
			}
		
		if (encontrado)
			return posicion;
		else
			return -1;
	}
	
	int PrimeraOcurrencia (char buscado){
		return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
	}
	
	int BusquedaBinaria (char buscado){
		bool encontrado;		
		int izda = 0;
		int dcha = total_utilizados - 1;
		int centro = (izda + dcha) / 2;
		
		while (izda <= dcha && !encontrado){
			if (vector_privado[centro] == buscado)
				encontrado = true;
			else if (buscado < vector_privado[centro])
				dcha = centro - 1;
			else
				izda = centro + 1;
			
			centro = (izda + dcha) / 2;
		}
		
		if (encontrado)
			return centro;
		else
			return -1;
	}
};

int LeeIntMayorIgualQue(int minimo){
	int numero;
	
	do{
		cin >> numero;
	}while (numero < minimo);
	
	return numero;
}

int LeeIntRango(int minimo, int maximo){
	int numero;
	
	do{
		cin >> numero;
	}while (numero < minimo || numero > maximo);
	
	return numero;
}

int main(){
	char caracter;
	const char TERMINADOR = '#';
	int izda, dcha;
	SecuenciaCaracteres secuencia;
	
	cout << "Introduce caracteres: ";
	cin.get(caracter);
	secuencia.Aniade(caracter);
	
	while (caracter != TERMINADOR){
		cin.get(caracter);
		if (caracter != TERMINADOR)
			secuencia.Aniade(caracter);
	}
	
	cout << "Introduzca las posiciones de los caracteres que desea eliminar: \n";
	cout << "Izquierda: ";
	izda = LeeIntMayorIgualQue(0);
	cout << "Derecha: ";
	dcha = LeeIntRango(izda, secuencia.TotalUtilizados() );
	
	secuencia.EliminaBloque(izda, dcha);

	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.GetVector(i);
	
	cout << "\n\n";
	
	system("pause");
}

