/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 12
Ejercicio 10: Moda dentro de la clase SecuenciaCaracteres

Defina el m�todo Moda dentro de la clase SecuenciaCaracteres. 
Este m�todo debe devolver un dato de tipo FrecuenciaCaracter (struct).

*/


#include <iostream>
#include <cctype>
using namespace std;

/*Almacena de forma conjunta el car�cter 
y la frecuencia con la que aparece*/
struct FrecuenciaCaracter{
	char caracter;
	int frecuencia = 0;
};

class SecuenciaCaracteres{
private:	
	static const int TAMANIO = 1e5;	
	FrecuenciaCaracter vector_privado[TAMANIO];
	int util_vector;
	int maximo;
	char letra_mas_repetida = 'a';
	
public:
	SecuenciaCaracteres()
		:util_vector(0)
	{
	}
	
	/* M�todo p�blico que indica la posicion en la que se encuentra un caracter.
	En caso de que no exista, devuelve una posici�n no v�lida */
	int EstaCaracter(char caracter){
		bool existe_caracter = false;
		int posicion;	
		
		for (int i = 0; i < util_vector && !existe_caracter ; i++)
			if(vector_privado[i].caracter == caracter){
				existe_caracter = true;
				posicion = i;
			}
		
		if (!existe_caracter)
			posicion = -1;		
			
		return posicion;	
	}
		
	void Aniade(char caracter){
		int posicion = EstaCaracter(caracter);
		
		if (posicion == -1){													// Si la posici�n es -1 (no v�lida), se le asigna una posici�n al final del vector
			vector_privado[util_vector].caracter = caracter;
			vector_privado[util_vector].frecuencia = 1;
			util_vector++;
		}
		else
			vector_privado[posicion].frecuencia++;		
	}
	
	FrecuenciaCaracter Moda(){
		maximo = vector_privado[0].frecuencia;
		letra_mas_repetida = vector_privado[0].caracter;
		
		for (int i = 1 ; i < util_vector ; i++){						// Calcula cual es el caracter que tiene m�s apariciones
			if(maximo < vector_privado[i].frecuencia && vector_privado[i].caracter != ' '){
				maximo = vector_privado[i].frecuencia;
				letra_mas_repetida = vector_privado[i].caracter;
			}
		}		
	}
	
	int Maximo(){
		return maximo;
	}
	
	char LetraMasRepetida(){
		return letra_mas_repetida;
	}
};

int main(){
	// Declaraci�n de variables
	const char TERMINADOR = '#';	
	char caracter;
	SecuenciaCaracteres secuencia;
	
	// Entrada de datos y c�mputos
	cin.get(caracter);
	caracter = tolower(caracter);
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		
		cin.get(caracter);
		caracter = tolower(caracter);
	}

	secuencia.Moda();	

	// Salida de resultados
	cout << "La letra que mas se repite es: " << secuencia.LetraMasRepetida() << " y se repite " << secuencia.Maximo() << " veces \n\n";
	
	system("pause");
}
