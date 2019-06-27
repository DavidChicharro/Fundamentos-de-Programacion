/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingenier�a Inform�tica
Asignatura: Fundamentos de la Programaci�n
Curso: 1� 	Grupo: C		Subgrupo: C1
Profesor Teor�a: Juan Carlos Cubero
Proferosa Pr�cticas: Mar�a del Carmen Pegalajar

Ejercicio 48: Gaussiana con men�

Primero se definen los par�metros de la funci�n, y el programa calcular� 
el valor de 'y' seg�n los valores y tramos de 'x' previamente definidos.
El programa adem�s dispondr� de dos men�s que permitir�n realizar diferentes acciones.
Finalmente los valores de 'y' se imprimir�n en pantalla.
*/

#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int main(){
	const double PI = 3.14159265;
	double esperanza, desviacion, x, y, divisor, exponencial,
			 minimo, maximo, incremento, salto_de_incremento;
	char opcion_menu_principal, opcion_menu_secundario;		 
		
	do{
		do{
			cout << "\nIntroduzca 'P' si desea introducir los parametros " << endl <<
					  "o 'S' si desea salir del programa ";
			cin >> opcion_menu_principal;
		
			opcion_menu_principal = toupper(opcion_menu_principal);
		}while (opcion_menu_principal != 'P' && opcion_menu_principal != 'S');
		
		if (opcion_menu_principal == 'P'){
		cout << "\nIntroduzca el valor de la esperanza o media ";
		cin >> esperanza;
	
			do{
				cout << "Introduzca el valor de la desviacion tipica. " <<
						  "Debe ser un valor positivo: ";
				cin >> desviacion;
			}while (desviacion < 0);
		
			do{
				cout << "\nIntroduzca 'R' si desea introducir el rango de valores de abscisas " << endl <<
						  "o 'V' si desea volver al menu anterior ";
				cin >> opcion_menu_secundario;
			
				opcion_menu_secundario = toupper(opcion_menu_secundario);
			}while (opcion_menu_secundario != 'R' && opcion_menu_secundario != 'V');
		}
	}while (opcion_menu_secundario == 'V');
	
		if (opcion_menu_secundario == 'R' && opcion_menu_principal == 'P'){
			cout << "\nIndique entre que valores se representara la funcion en el eje x \n";
			cout << "Minimo: ";
			cin >> minimo;
			cout << "Maximo: ";
	
			do{
				cin >> maximo;
			}while (maximo < minimo);
	
			cout << "Introduzca el incremento de los valores a representar: ";
	
			do{
				cin >> salto_de_incremento;
			}while (salto_de_incremento < 0);
	
			x = minimo;
			incremento = 0;
	
			while (x <= maximo){
				exponencial = -0.5 * pow(((x - esperanza) / desviacion), 2);
				divisor = desviacion * sqrt(2 * PI);
				y = (1.0 / divisor) * exp(exponencial);
		
				cout << "\n f(" << x << ")= " << y;
		
				incremento++;
				x = minimo + incremento * salto_de_incremento;
			}
		}
		
		cout << "\n\nFin del programa \n\n";
		
	system ("pause");
}
