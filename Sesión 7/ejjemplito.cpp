/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

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


