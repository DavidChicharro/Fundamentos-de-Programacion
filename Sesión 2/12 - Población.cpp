/*
Programa que calcula la estimación de la población de un territorio después de 
tres años. Para ello, el programa debe leer la población inicial, la tasa de natalidad,
la de mortalidad y la tasa de migración. Ésta última es la diferencia entre los que se
van y los que vienen, por lo que puede ser o bien positiva o bien negativa.
Suponga que todos los datos son enteros.
Una vez calculada la población que habrá el siguiente año, las tasas se vuelven a
aplicar sobre la población obtenida, y así sucesivamente, tantos años como estemos interesados.
*/

#include <iostream>

using namespace std;

int main(){
	int poblacion_inicial, tasa_natalidad, tasa_mortalidad, tasa_migracion;
	int poblacion_primer_anio, poblacion_segundo_anio, poblacion_tercer_anio;
	
	cout << "Inserte el numero inicial de habitantes del territorio ";
	cin >> poblacion_inicial;
	cout << "Indique la tasa de natalidad (por cada 1000 habitantes) ";
	cin >> tasa_natalidad;
	cout << "Indique la tasa de mortalidad (por cada 1000 habitantes) ";
	cin >> tasa_mortalidad;
	cout << "Indique la tasa de migracion (por cada 1000 habitantes) ";
	cin >> tasa_migracion;
	
	poblacion_primer_anio = poblacion_inicial + 
									(poblacion_inicial * tasa_natalidad / 1000.0) - 
									(poblacion_inicial * tasa_mortalidad / 1000.0) + 
									(poblacion_inicial * tasa_migracion / 1000.0);
								 
	poblacion_segundo_anio = poblacion_primer_anio +
									 (poblacion_primer_anio * tasa_natalidad / 1000.0) -
								    (poblacion_primer_anio * tasa_mortalidad / 1000.0) +
								    (poblacion_primer_anio * tasa_migracion / 1000.0);
								  
	poblacion_tercer_anio = poblacion_segundo_anio +
									(poblacion_segundo_anio * tasa_natalidad / 1000.0) -
								   (poblacion_segundo_anio * tasa_mortalidad / 1000.0) +
								   (poblacion_segundo_anio * tasa_migracion / 1000.0);							  
	
	cout << "\nLa poblacion del territorio al cabo de tres anios sera de " << poblacion_tercer_anio << " habitantes \n\n";
	
	system ("pause");
}
