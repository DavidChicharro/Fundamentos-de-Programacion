/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 12
Ejercicio 14 - Elimina todas las ocurrencias de un carácter. Versión eficiente

El algoritmo del ejercicio 11 es muy ineficiente
ya que requiere trasladar muchas veces muchas posiciones (usa dos bucles anidados). Para comprobarlo, recupere el texto
http://decsai. ugr.es/~carlos/FP/Quijote_con _ruido.txt

En él aparecen numerosas ocurrencias del carácter '~' (código ASCII 126) como
ruido en el texto y se quieren eliminar. Si aplica el algoritmo ineficiente, la ejecución
puede tardar más de 12 minutos.

Para resolver eficientemente este problema se propone utilizar dos variables,
posicion_lectura y posicion_escritura   que nos vayan indicando, en cada momento, 
la componente que se está leyendo y el sitio dónde tiene que escribirse. 
Por ejemplo, supongamos que en un determinado momento la variable
posicion_lectura vale 6 y posicion_escritura 3. 
Si la componente en la posición 6 es el carácter a borrar, simplemente avanzaremos posicion_lectura.

En caso contrario, la colocaremos en la posición 3 y avanzaremos una posición ambas variables.

Implemente este algoritmo y observe la diferencia de tiempo al ejecutarlo sobre el Quijote,

ya que ahora el tiempo de ejecución es de unos 8 milisegundos.

Como ampliación: si quiere saber con exactitud el tiempo de ejecución, puede utilizar
un objeto de la clase Cronometro tal y como se vio en el ejercicio 24 de la relación de problemas III.
*/


#include <iostream>
#include <string>
using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 1e5;
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
	
	void EliminaOcurrencias(char a_borrar){
		int posicion_lectura = 0;
		int posicion_escritura = 0;
		int borrados = 0;
		
		for (int i = posicion_lectura ; i < total_utilizados ; i++){
			if (vector_privado[i] == a_borrar)
				borrados++;
			else{
				vector_privado[posicion_escritura] = vector_privado[i];
				posicion_escritura++;
			}
		}
		total_utilizados = total_utilizados - borrados;
	}
	
	void EliminaBloque(int izda, int dcha){
		int numero_a_borrar = dcha - izda + 1;
		
		for (int i = dcha + 1 ; i < total_utilizados ; i++){
			vector_privado[i - numero_a_borrar] = vector_privado[i];
			
		}
		total_utilizados = total_utilizados - numero_a_borrar;
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
	
	secuencia.EliminaOcurrencias(caracter_a_eliminar);	

	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.GetVector(i);
		
	cout << "\n\n";
	
	system("pause");
}
