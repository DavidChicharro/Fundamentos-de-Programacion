/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Ejercicio 

*/

#include <iostream>

using namespace std;

int main(){
	int suma, i, j, n;
	
	suma = 0;
	
	cin >> n;
	
	for (i=1 ; i<=n ; i++){
		for (j=i ; j<=n ; j++){
			suma = j + i;
			cout << suma << "  ";
		}
	cout << "\n";
	}
		
	cout << suma;
}


