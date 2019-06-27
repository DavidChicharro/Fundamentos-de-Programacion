#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	cout << "Rangos de int y double:\n";
	cout << "int:\n";
	cout << numeric_limits<int>::min() << "\n" ;
	cout << numeric_limits<int>::max() << "\n" ;
	
	cout << "double:\n";
	cout << numeric_limits<double>::min(-98.63) << "\n" ;
	cout << numeric_limits<double>::max(896.658) << "\n" ;
}
