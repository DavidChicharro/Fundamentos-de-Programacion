/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 12
Ejercicio 11 - Elimina todas las ocurrencias de un carácter. Versión ineficiente

Sobre la clase SecuenciaCaracteres, añada el método EliminaOcurrencias 
para eliminar todas las apariciones de un determinado carácter a_borrar.

Un primer algoritmo para resolver este problema sería el siguiente:

class SecuenciaCaracteres{
	.........
	void EliminaOcurrenciasERROR(){
		for (int i = 0; i < total_utilizados; i++)
			if (vector_privado[i] == a_borrar)
				Elimina(i);
	}
};

El anterior código tiene un fallo. ¿Cuál? Pruébelo con cualquier secuencia que tenga
el carácter a borrar dos veces consecutivas. Proponga una solución e impleméntela

*/

/*
El método Elimina que se ha propuesto sólo consigue borrar un caracter 
cuando hay dos seguidos que son iguales, puesto que el caracter repetido
pasa a la posición anterior mientras que en el bucle 'for' se pasa al caracter siguiente.

La solución pasa por cambiar el 'if' por un 'while'.

El programa leerá caracteres que irá almacenando en un vector.
Después pedirá que se introduzca el caracter que se desea eliminar 
tantas veces como aparezca. El programa eliminará el caracter deseado
e imprimirá en pantalla los caracteres introducidos al principio sin 
los que se ha pedido eliminar.

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
	

int main(){
	char caracter, caracter_a_eliminar;
	const char TERMINADOR = '#';
	SecuenciaCaracteres secuencia;
	
	cout << "Introduce caracteres: ";
	cin.get(caracter);
	secuencia.Aniade(caracter);
	
	while (caracter != TERMINADOR){
		cin.get(caracter);
		if (caracter != TERMINADOR)
			secuencia.Aniade(caracter);
	}
		
	cout << "Introduzca el caracter que desea eliminar: ";
	cin >> caracter_a_eliminar;
	
	secuencia.EliminaOcurrenciasERROR(caracter_a_eliminar);	

	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.GetVector(i);
	
	system("pause");
}
