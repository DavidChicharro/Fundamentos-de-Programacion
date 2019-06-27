/*Calcule el número de segundos que hay entre
dos instantes del mismo día. Cada instante se
caracteriza por la hora (entre 0 y 23), minuto
(entre 0 y 59) y segundo (entre 0 y 59).
El programa leerá la hora, minuto y segundo del
instante inicial y la hora, minuto y segundo del
instante final (supondremos que los valores
introducidos son correctos) y mostrará el número
de segundos entre ambos instantes */

#include <iostream>

using namespace std;

int main(){
	double hora1, hora2, minuto1, minuto2, segundo1, segundo2, hora_total, minuto_total, segundo_total ;
	
	cout << "Introduzca el primer instante del dia " ;													//MEJORAR PROGRAMA
	cin >> hora1 ;
	cin >> minuto1 ;
	cin >> segundo1 ;
	cout << "Introduzca el segundo instante del dia " ;
	cin >> hora2 ;
	cin >> minuto2 ;
	cin >> segundo2 ;
	
	hora_total = hora2 - hora1 ;
	minuto_total = minuto2 - minuto1 ;
	segundo_total = segundo2 - segundo1 ;
	
	cout << "El numero de segundos entre ambos instantes es " << hora_total << "\n" ;
	cout << minuto_total << "\n" ;
	cout << segundo_total << "\n" ;
	
	system ("pause") ;
}
