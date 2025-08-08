#include <iostream>
#include <math.h>
using namespace std;

int inverse(int num) {
	int num1 = 0;
	int pl = 1;
	while (num != 0){
		int rem = num % 10;
		num1 = num1 + pl*pow(10, rem-1);
		num = num/10;
		pl ++;
	}
	return num1;
}

int main(){
	int n;
	cin >> n;
	cout << inverse(n) << endl;
}