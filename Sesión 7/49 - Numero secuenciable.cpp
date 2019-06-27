/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 49: N�mero secuenciable

Programa que lee un numero entero positivo y calcula si es secuenciable, es decir 
si se puede generar como suma de n�meros consecutivos (al menos dos). El programa 
imprimir� en pantalla todas las descomposiciones posibles.
*/

#include <iostream>

using namespace std;

int main(){
	int numero_secuenciable, i, ultimo_i;
	int suma = 0;
	bool continuar;
	
	do{
		cout << "Introduzca el numero secuenciable: ";
		cin >> numero_secuenciable;
	}while(numero_secuenciable < 1);
	
	ultimo_i = numero_secuenciable - 1;
	
	for (i = ultimo_i ; i >= 1 ; i++){
		suma = suma + i;
		
		if(suma == numero_secuenciable){
			suma = 0;
			continuar = true;
			cout << "\nEl numero es suma de: ";
			
			for(i ; i >= 1 && continuar ; i--){				// Dice los sumandos
				cout << i << " ";
				suma = suma + i;
				if (suma == numero_secuenciable)				// Para que salga
					continuar = false;
			}
			
			ultimo_i--;
			i = ultimo_i;
		}
		else if (suma > numero_secuenciable){
			ultimo_i--;
			i = ultimo_i;		
			suma = 0;
		}
	}
	
	cout << "\n\n";
	
	system ("pause");
}
