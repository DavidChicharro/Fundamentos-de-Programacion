/*
Recuperar la soluci�n del ejercicio 4.
Adem�s de mostrar el salario con la subida del 2% se quiere
mostrar el salario resultante de subirle otro 3% adicional
(adem�s de la subida del 2%). El programa debe mostrar los
salarios resultantes de ambas subidas.
*/

#include <iostream>

using namespace std;

int main(){
	const double PRIMER_INCREMENTO = 1.02, SEGUNDO_INCREMENTO = 1.03;
	double salario_base, salario_final_1, salario_final_2 ;
	
	cout << "Introduzca el salario base ";
	cin >> salario_base;
	
	salario_final_1 = salario_base * PRIMER_INCREMENTO;
	salario_final_2 = salario_final_1 * SEGUNDO_INCREMENTO;								
	
	cout << "El salario tras la primera subida es " <<  salario_final_1;
	cout << "\nEl salario tras la segunda subida es " << salario_final_2 << "\n\n";

	system ("pause") ;
}

/* Este programa ha sido reescrito, seg�n se�ala el problema 11, utendiendo al uso de constantes. 
Por tanto es v�lido tanto para dicho ejercicio como para el mismo n� 9 que se ped�a para la Sesi�n 2*/
