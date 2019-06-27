/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Sesi�n 12
Ejercicio 14 - Elimina todas las ocurrencias de un car�cter. Versi�n eficiente

El algoritmo del ejercicio 11 es muy ineficiente
ya que requiere trasladar muchas veces muchas posiciones (usa dos bucles anidados). Para comprobarlo, recupere el texto
http://decsai. ugr.es/~carlos/FP/Quijote_con _ruido.txt

En �l aparecen numerosas ocurrencias del car�cter '~' (c�digo ASCII 126) como
ruido en el texto y se quieren eliminar. Si aplica el algoritmo ineficiente, la ejecuci�n
puede tardar m�s de 12 minutos.

Para resolver eficientemente este problema se propone utilizar dos variables,
posicion_lectura y posicion_escritura   que nos vayan indicando, en cada momento, 
la componente que se est� leyendo y el sitio d�nde tiene que escribirse. 
Por ejemplo, supongamos que en un determinado momento la variable
posicion_lectura vale 6 y posicion_escritura 3. 
Si la componente en la posici�n 6 es el car�cter a borrar, simplemente avanzaremos posicion_lectura.

En caso contrario, la colocaremos en la posici�n 3 y avanzaremos una posici�n ambas variables.

Implemente este algoritmo y observe la diferencia de tiempo al ejecutarlo sobre el Quijote,

ya que ahora el tiempo de ejecuci�n es de unos 8 milisegundos.

Como ampliaci�n: si quiere saber con exactitud el tiempo de ejecuci�n, puede utilizar
un objeto de la clase Cronometro tal y como se vio en el ejercicio 24 de la relaci�n de problemas III.
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
	
	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
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
};

int main(){
	char caracter, caracter_a_eliminar;
	const char TERMINADOR = '#';
	SecuenciaCaracteres secuencia;
	
	cout << "Introduce caracteres: ";
	cin.get(caracter);
	secuencia.Aniade(caracter);
	
	while (caracter != TERMINADOR){
		secuencia.Aniade(caracter);
		cin.get(caracter);
	}
		
	cout << "Introduzca el caracter que desea eliminar: ";
	cin >> caracter_a_eliminar;
	
	secuencia.EliminaOcurrencias(caracter_a_eliminar);	

	for (int i = 0 ; i < secuencia.TotalUtilizados() ; i++)
		cout << secuencia.GetVector(i);
		
	cout << "\n\n";
	
	system("pause");
}
