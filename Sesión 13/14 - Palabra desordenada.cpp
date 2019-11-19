/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 14 - Palabra desordenada (Examen Examen Febrero 2009)

Programa que lee dos secuencias, una ordenada y otra desordenada. Se comprobará su similutud, es decir,
que la primera y la última letra de sendas secuencias coincidan y que el resto de letras sean las
mismas aunque no estén necesariamente en las mismas posiciones; el programa determinará si son similares
y se imprimirá en pantalla si lo son o no.

*/

#include <iostream>
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
	
	bool SecuenciaSimilar (SecuenciaCaracteres secuencia_desordenada){
		int posicion;
		bool es_similar = false;
		
		if (total_utilizados == secuencia_desordenada.total_utilizados &&
			 vector_privado[1] == secuencia_desordenada.vector_privado[0] &&
			 vector_privado[total_utilizados] == secuencia_desordenada.vector_privado[total_utilizados]){
			es_similar = true;
			
			for (int i = 1 ; i < total_utilizados - 1 && es_similar ; i++){
				posicion = PrimeraOcurrenciaEntre(i, total_utilizados -1, secuencia_desordenada.vector_privado[i]);
				if (posicion != -1)
					es_similar = true;
				else
					es_similar = false;
			}
		}
			 		
		return es_similar;
	}
};


int main(){
	const char TERMINADOR = '#';
	char caracter;
	SecuenciaCaracteres secuencia_desordenada, secuencia_ordenada;
	bool son_similares;	
	
	// Entrada de datos
	cout << "Introduzca los caracteres de manera desordenada: ";
	cin.get(caracter);
	
	while (caracter != TERMINADOR){
		secuencia_desordenada.Aniade(caracter);
		cin.get(caracter);
	}
		
	cout << "Introduzca los caracteres de manera ordenada: ";
	cin.get(caracter);	
	
	while (caracter != TERMINADOR){
		secuencia_ordenada.Aniade(caracter);
		cin.get(caracter);
	}
	
	// Cómputos
	son_similares = secuencia_ordenada.SecuenciaSimilar(secuencia_desordenada);
	
	// Salida de resultados
	if (son_similares)
		cout << "Las palabras son similares \n";
	else
		cout << "No son similares \n";
		
	system ("pause");
}
