/*
Escriba un programa que lea un valor entero e imprima en pantalla cada uno de sus
dígitos separados por dos espacios en blanco. Supondremos que el usuario introduce
siempre un entero de tres dígitos.
*/

#include <iostream>

using namespace std;

int main(){
	int numero_3_digitos, numero_2_digitos, primer_digito, segundo_digito, tercer_digito;
	
	cout << "Introduce un valor de 3 digitos ";
	cin >> numero_3_digitos;
	
	primer_digito = numero_3_digitos / 100;
	numero_2_digitos = numero_3_digitos % 100;
	
	segundo_digito = numero_2_digitos / 10;
	tercer_digito = numero_2_digitos % 10;
	
	cout << primer_digito << "  " << segundo_digito << "  " << tercer_digito << "\n\n";
	
	system ("pause");
}
