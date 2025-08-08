#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	int d = pow(b,2) - 4*a*c;
	if (d > 0){
		cout << "Real and Distinct" << endl;
		int x = (-b - sqrt(d))/2*a;
		cout << x << " ";
		int y = (-b + sqrt(d))/2*a;
		cout << y;
	}
	else if (d == 0){
		cout << "Real and Equal" << endl;
		int x = (-b - sqrt(d))/2*a;
		cout << x << " ";
		cout << x;
	}
	else if (d < 0){
		cout << "Imaginary" << endl;
	}
	return 0;
}