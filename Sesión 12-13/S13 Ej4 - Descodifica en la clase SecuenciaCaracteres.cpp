/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 13
Ejercicio 4 - Descodifica en la clase SecuenciaCaracteres

El programa lee una secuencia de caracteres. Despu�s, mediante un m�todo
de la clase SecuenciaCaracteres, descodifica los caracteres introducidos 
e imprime por pantalla el resultado descodificado.

*/

#include <iostream>
#include <string>
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

	SecuenciaCaracteres Descodifica (){
		SecuenciaCaracteres descodificado;		
		bool anterior_blanco = true;
		
		for (int i = 0 ; i < total_utilizados ; i++){
			if (vector_privado[i] != ' '){										// Si el caracter de la posici�n actual no es un espacio en blanco
				if (vector_privado[i+1] == ' ' || anterior_blanco)			// y si el caracter siguiente o el anterior son espacios en blanco
					descodificado.Aniade(vector_privado[i]);					// entonces se a�ade el caracter al vector de la nueva clase de descodificados
				
				anterior_blanco = false;											// Al entrar en este bloque 'if' el caracter se define como distinto a un espacio en blanco
			}
			else
				anterior_blanco = true;
		}		

		return descodificado;
	}
};

int main(){
	const char TERMINADOR = '#';
	char caracter;
	SecuenciaCaracteres secuencia, descodificado;
	
	// Entrada de datos
	cin.get(caracter);
	
	while (caracter != TERMINADOR && secuencia.TotalUtilizados() < secuencia.Capacidad() ){
		secuencia.Aniade(caracter);
		cin.get(caracter);
	}
	
	// C�mputos
	descodificado = secuencia.Descodifica();
	
	// Salida de resultados
	for (int i = 0 ; i < descodificado.TotalUtilizados() ; i++)
		cout << descodificado.GetVector(i);

	cout << "\n\n";

	system("pause");
}
