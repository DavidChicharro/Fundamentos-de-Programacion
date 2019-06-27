/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 13
Ejercicio 9 - Inserta secuencia eficiente

Programa que pide una secuencia de caracteres y una posici�n de inserci�n 
para insertar otra secuencia que se introducir� en el paso siguiente en 
dicha posici�n. Una vez introducidos todos los datos, el programa realizar� 
la inserci�n y se mostrar� en pantalla el resultado definitivo.

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
	
	void Inserta(int pos_insercion, SecuenciaCaracteres secuencia_a_insertar){
		int num_caracteres_insercion = secuencia_a_insertar.TotalUtilizados();
		
		if (total_utilizados < TAMANIO){
			for (int i = total_utilizados + num_caracteres_insercion ; i > pos_insercion ; i--)
				vector_privado[i] = vector_privado[i - num_caracteres_insercion];							// Se desplazan los caracteres del vector desde la posici�n de inserci�n
			
			for (int i = 0 ; i < num_caracteres_insercion ; i++)
				vector_privado[pos_insercion + i] = secuencia_a_insertar.Elemento(i);					// Se insertan los caracteres del objeto 'insercion'
				
			total_utilizados = total_utilizados + num_caracteres_insercion;
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
	int posicion_insercion;
	SecuenciaCaracteres secuencia, insercion;
	
	// Entrada de datos
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
		
	while (caracter != TERMINADOR){
		insercion.Aniade(caracter);									// El objeto 'insercion' almacena los caracteres a insertar
		cin.get(caracter);
	}
	
	// C�mputos
	secuencia.Inserta(posicion_insercion, insercion);
	
	// Salida de resultados
	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.Elemento(i);
		
	cout << "\n\n";
	
	system ("pause");
}
