/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 5 - Moda

El programa lee una secuencia de caracteres y calcula cual es la letra que
más apariciones tiene de todos los introducidos. Una vez calculado, dicha 
letra se imprime en pantalla junto a su número de apariciones.

*/

#include <iostream>
using namespace std;

/* struct que almacena cada caracter con su número de apariciones */
struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 1e6;
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
	
	FrecuenciaCaracter Moda(){
		SecuenciaCaracteres procesados;
		FrecuenciaCaracter moda;
		int apariciones, minimo = 0;
		
		for (char i = 'a' ; i <= 'z' ; i++)
			procesados.Aniade(i);
			 
		for (int i = 0 ; i < procesados.TotalUtilizados() ; i++){
			apariciones = NumeroOcurrencias(procesados.Elemento(i), 0, total_utilizados);
			
			if (apariciones > minimo){
				moda.caracter = procesados.Elemento(i);
				moda.frecuencia = apariciones;
				minimo = apariciones;
			}
		}
		
		return moda;
	}
	
	int NumeroOcurrencias(char buscado, int izda, int dcha){
		int num_ocurrencias = 0;
		
		for (int i = izda ; i < dcha ; i++)
			if (vector_privado[i] == buscado)
				num_ocurrencias++;		
		
		return num_ocurrencias;	
	}
};

int main(){
	// Declaración de variables
	const char TERMINADOR = '#';	
	char caracter;
	SecuenciaCaracteres secuencia;
	FrecuenciaCaracter moda;
	
	// Entrada de datos
	cin.get(caracter);
	caracter = tolower(caracter);
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		
		cin.get(caracter);
		caracter = tolower(caracter);
	}

	// Cómputos
	moda = secuencia.Moda();	

	// Salida de resultados
	cout << "La letra que mas se repite es: " << moda.caracter << " y se repite " << moda.frecuencia << " veces \n\n";
	
	system("pause");
}
