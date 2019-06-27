/*
Se pide leer dos enteros min y max que representar�n un rango de valores.
	El minimo debe ser un n�mero positivo y el maximo, mayor que el minimo.
Una vez le�dos ambos valores, se introducir� otro entero nuevo obligando a que
est� dentro del intervalo [min, max]. Si el usuario introduce m�s de 3 valores fuera
del rango, el bucle terminar� y se mostrar� en pantalla un mensaje que indique que se
super� el n�mero de intentos m�ximo. Si se introduce un valor en el rango pedido se
mostrar� en pantalla el resultado de calcular (nuevo - min) y (max - nuevo).
*/

#include <iostream>

using namespace std;

int main(){
	int minimo, maximo, numero_en_rango, intentos, nuevo_1, nuevo_2;
	bool continuar, condicion_1;
	
	// Entrada de datos
	
	cout << "Introduzca un valor, que sera el minimo: ";
	
	do{
		cin >> minimo;
	}while (minimo <= 0);
	
	cout << "Introduzca un valor, que sera el maximo: ";
	
	do{
		cin >> maximo;
	}while (maximo <= minimo);
	
	cout << "Introduzca un numero que este dentro del rango: ";
	
	// C�mputos
	
	intentos = 1;
	continuar = true;
	
	while (intentos <= 3 && continuar){
		cin >> numero_en_rango;
		
		if (numero_en_rango > minimo && numero_en_rango < maximo){
			nuevo_1 = numero_en_rango - minimo;
			nuevo_2 = maximo - numero_en_rango;			
			continuar = (intentos > 3);
			condicion_1 = true;
		}
		else
			intentos++;
	}

	// Salida de resultados

	if (condicion_1)
		cout << "\n\n" << nuevo_1 << "\t" << nuevo_2 << "\n\n";
	else
		cout << "\n\nHa superado el numero maximo de intentos \n\n";

	system ("pause");
}
