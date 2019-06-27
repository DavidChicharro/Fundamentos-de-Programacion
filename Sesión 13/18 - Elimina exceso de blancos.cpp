/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 13
Ejercicio 18 - Elimina exceso de blancos 

Programa que lee una secuencia de caracteres y elimina todos los espacios en blanco
sobrantes siempre que haya dos o m�s espacios, dejando s�lo uno. Finalmente mostrar�
el resultado en pantalla con la misma secuencia de entrada pero sin los espacios sobrantes.

*/

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 1e6;
	char vector_privado[TAMANIO];
	int total_utilizados;

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

	void EliminaExcesoBlancos(){
		for (int i = 0 ; i < total_utilizados ; i++)
			if (vector_privado[i] == ' ' && vector_privado[i+1] == ' ')  		// Cuando el caracter actual y el siguiente sean espacios en blanco
				while (vector_privado[i+1] == ' '){										// Mientras que el caracter siguiente a un espacio sea otro espacio
					for (int j = i ; j < total_utilizados ; j++)						// Se desplazar�n todos los caracteres una posici�n a la izquierda
						vector_privado[j] = vector_privado[j+1];						
					
					total_utilizados--;
				}
	}
};

int main(){
	const char TERMINADOR = '#';
	char caracter;
	SecuenciaCaracteres secuencia;
	
	// Entrada de datos
	cout << "Introduzca una cadena de caracteres hasta el terminador " << TERMINADOR << ": " << endl;
	cin.get(caracter);
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		cin.get(caracter);
	}
	
	// C�mputos
	secuencia.EliminaExcesoBlancos();
	
	// Salida de resultados
	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.Elemento(i);
		
	cout << "\n\n";
	
	system ("pause");
}
