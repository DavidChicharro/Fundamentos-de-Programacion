/*
Dadas las variables count = 0, limit = 10,
x = 2, y = 7, calcule el valor de las 
siguientes expresiones lógicas:

1	count == 0 && limit < 20
2	limit > 20 || count < 5
3	!(count == 12)
4	count == 1 && x < y
5	!((count < 10 || x < y) && count >= 0 )
6	(count > 5 && y == 7) || (count <= 0 limit == 5*x)
7	!(limit != 10 && z > y)
*/

#include <iostream>

using namespace std;

int main(){
	bool uno, dos, tres, cuatro, cinco, seis, siete;
	const int count = 0, limit = 10, x = 2, y = 7;
	
	uno = count == 0 && limit < 20;
	dos = limit > 20 || count < 5;
	tres = !(count == 12);
	cuatro = count == 1 && x < y;
	cinco = !((count < 10 || x < y) && count >= 0 );
	seis = (count > 5 && y == 7) || (count <= 0 && limit == 5*x); 		//Error logico - añado && final
	siete = !(limit != 10 && x > y);											//Error logico - cambio 'z' por 'x'
	
	cout << "1: " << uno << "\n2: " << dos <<  "\n3: " << tres <<
			  "\n4: " << cuatro << "\n5: " << cinco << "\n6: " << seis <<
			   "\n7: " << siete << "\n\n";
			   
	system ("pause");
}
