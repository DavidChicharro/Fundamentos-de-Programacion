/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 12
Ejercicio 13 - Elimina un bloque de caracteres. Versión eficiente

Para borrar el bloque entre izda y dcha:

	Calcular num_a_borrar como dcha - izda + 1
		Recorrer las componentes -i- de la secuencia	entre las posiciones dcha+1 hasta el final
			Colocar la componente -i- en la posición i-num_a_borrar
		Actualizar total_utilizados
		
Este algoritmo resuelve el problema con un único bucle mientras que la versión ineficiente recurría a dos bucles anidados

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
	
	char Elemento(int indice){
		return vector_privado[indice];
	}			
	
	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	void EliminaBloqueEficiente(int izda, int dcha){
		int numero_a_borrar = dcha - izda + 1;
		
		for (int i = dcha + 1 ; i < total_utilizados ; i++){
			vector_privado[i - numero_a_borrar] = vector_privado[i];
			
		}
		total_utilizados = total_utilizados - numero_a_borrar;
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
		secuencia.Aniade(caracter);
		cin.get(caracter);
	}
	
	cout << "Introduzca las posiciones de los caracteres que desea eliminar: \n";
	cout << "Izquierda: ";
	izda = LeeIntMayorIgualQue(0);
	cout << "Derecha: ";
	dcha = LeeIntRango(izda, secuencia.TotalUtilizados() );
	
	secuencia.EliminaBloqueEficiente(izda, dcha);

	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.Elemento(i);
	
	cout << "\n\n";
	
	system("pause");
}
