/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 13 - Counting Sort

Programa que lee una secuencia de caracteres y los devuelve de manera ordenada en pantalla

*/

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 100;
	char vector_privado[TAMANIO];
	int total_utilizados;
	
	void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      double intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
	
public:
	SecuenciaCaracteres()
		:total_utilizados(0) {
	}
	
	int Capacidad(){
		return TAMANIO;
	}
	
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	char Elemento(int indice){
		return vector_privado[indice];
	}

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
			
	int PosicionMinimoEntre(int izda, int dcha){
		char minimo = vector_privado[izda];
		int posicion_minimo = -1;
		
		for (int i = izda + 1 ; i <= dcha ; i++)
			if (minimo > vector_privado[i]){
				minimo = vector_privado[i];
				posicion_minimo = i;
			}
			
		return posicion_minimo;
	}
	
	int PosicionMinimo(){										
		return PosicionMinimoEntre(0, total_utilizados - 1);
	}
	
	int PosicionMaximoEntre (int izda, int dcha){		
		char maximo = vector_privado[izda];
		int posicion_maximo = -1;
		
		for (int i = izda + 1 ; i <= dcha ; i++)
			if (maximo < vector_privado[i]){
				maximo = vector_privado[i];
				posicion_maximo = i;
			}
			
		return posicion_maximo;
	}
	
	int PosicionMaximo(){
		return PosicionMaximoEntre(0, total_utilizados - 1);
	}
   
   int FrecuenciaCaracter(char buscado){
   	int apariciones = 0;
   	
   	for (int i = 0 ; i < total_utilizados ; i++)
   		if (buscado == vector_privado[i])
   			apariciones++;
   			
   	return apariciones;
   }
   
   SecuenciaCaracteres CountingSort(){
		SecuenciaCaracteres ordenados;
		const int MAXIMO_LOCAL = 1000;
		int vector_local[MAXIMO_LOCAL];
		int util_local = 0;
		bool esta_caracter;		
		char minimo = vector_privado[PosicionMinimo()];
		char maximo = vector_privado[PosicionMaximo()];
		char letra = minimo;
		
		for (char i = minimo ; i <= maximo ; i++){
			esta_caracter = false;
			
			for (int j = 0 ; j < total_utilizados && !esta_caracter ; j++)
				if (i == vector_privado[j]){													// Se entra en el bloque 'if' cuando coincide el caracter buscado con
					esta_caracter = true;														// el caracter del vector privado. Una vez encontrado no se vuelve a entrar para ese caracter
					vector_local[util_local] = FrecuenciaCaracter(i);					// El vector local guarda la frecuencia de cada caracter
					util_local++;
				}
		}		
		
		for (int i = 0 ; i < total_utilizados ; i++){			
			for (int j = 0 ; j < vector_local[i] && vector_local[i] != 0 ; j++)		// Se añade el caracter tantas veces como indique su frecuencia de aparicion
				ordenados.Aniade(letra);															// y se almacena en un nuevo objeto de la clase SecuenciaCaracteres
			
			letra++;
		}
	
		return ordenados;
	}
};

int main(){
	const char TERMINADOR = '#';
	char caracter;
	SecuenciaCaracteres secuencia, ordenados;
	
	// Entrada de datos
	cout << "Introduzca una cadena de caracteres: " << endl;
	cin >> caracter;
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		cin >> caracter;
	}
	
	// Cómputos
	ordenados = secuencia.CountingSort();
	
	// Salida de resultados
	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
      	cout << ordenados.Elemento(i);

	cout << "\n\n";

	system ("pause");
}
