/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 13
Ejercicio 8 - Inserta secuencia ineficiente 

Programa que pide una secuencia de caracteres y una posición de inserción 
para insertar otra secuencia que se introducirá en el paso siguiente en 
dicha posición. Una vez introducidos todos los datos, el programa realizará 
la inserción y se mostrará en pantalla el resultado definitivo.

*/

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 1e4;
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
	
	void Inserta(int pos_insercion, char valor_nuevo){
		if (total_utilizados < TAMANIO){
			for (int i = total_utilizados ; i > pos_insercion ; i--){
				vector_privado[i] = vector_privado[i-1];
			}
			
			vector_privado[pos_insercion] = valor_nuevo;
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
	
};

int main(){
	const char TERMINADOR = '#';
	char caracter;
	int posicion_insercion,
		 insertados = 0;
	SecuenciaCaracteres secuencia;
	
	cout << "Introduce una cadena de caracteres hasta introducir el terminador " << TERMINADOR << ": " << endl; 
	cin.get(caracter);
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		cin.get(caracter);
	}
	
	cout << "Indique la posicion de insercion: ";
	cin >> posicion_insercion;
	cout << "Introduce los caracteres a insertar hasta introducir el terminador " << TERMINADOR << ": " << endl;
	cin.get(caracter);		
	insertados++;
	
	for (int i = 0 ; i < insertados && caracter != TERMINADOR ; i++){		
		secuencia.Inserta(posicion_insercion+i , caracter);
		cin.get(caracter);
		insertados++;
	}
	
	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.Elemento(i);
		
	cout << "\n\n";
	
	system ("pause");
}
