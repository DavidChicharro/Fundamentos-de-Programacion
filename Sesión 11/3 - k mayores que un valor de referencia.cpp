/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 11
Ejercicio 3: k mayores que un valor de referencia, versión eficiente

Programa que lee un conjunto de números reales y los almacena en un vector. 
Se recorrerá después las componentes del vector original;
si es mayor que la referencia, insertar dicho valor de forma ordenada en el vector "mayores_que",
y éste siempre tendrá, como mucho, k componentes.
Dichas componentes se imprimirán en pantalla.

*/

#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   double dato, referencia, a_desplazar;
   const int TAMANIO = 1e5;
   double vector[TAMANIO], mayores_que[TAMANIO];
   int utilizados_vector, utilizados_mayores_que, k;

	cout << "k valores mayores que."
        << "\nIntroduzca reales con terminador "
        << TERMINADOR << "\n"
        << "Luego introduzca el valor de referencia y k.\n";
        
   utilizados_vector = 0;
   cin >> dato;
   
   for (utilizados_vector = 0 ; dato != TERMINADOR && utilizados_vector < TAMANIO ; utilizados_vector++){
		vector[utilizados_vector] = dato;
		cin >> dato;
	}
	
	cout << "Inserte la referencia: ";
   cin >> referencia;
   cout << "Indique cuantos se seleccionaran mayores que " << referencia << ": ";
   cin >> k;
   
   int i;
   utilizados_mayores_que = 0;
   
   for (i = 0 ; i < utilizados_vector ; i++){	
   	if (vector[i] >= referencia && utilizados_mayores_que < k){
			mayores_que[utilizados_mayores_que] = vector[i];
   		utilizados_mayores_que++;
   	}
   	
   	for (int izda = 1 ; izda < utilizados_mayores_que ; izda++){
			a_desplazar = mayores_que[izda];
			int j;
			for (j = izda ; j > 0 && a_desplazar < mayores_que[j-1] ; j--)
				mayores_que[j] = mayores_que[j-1];
			
			mayores_que[j] = a_desplazar;
		}
   }

	for (int j = 0; j < utilizados_mayores_que; j++){
      cout << mayores_que[j] << " ";
   }
   
   system("pause");
}
