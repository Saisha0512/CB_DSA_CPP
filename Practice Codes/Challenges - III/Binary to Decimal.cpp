#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int pl = 1;
	int num = 0;
	if (n == 0){
		cout << 0 << endl;
	}
	else {
		while (n != 0){
			int rem = n % 10;
			num = num + rem*pow(2,pl - 1);
			pl ++;
			n = n/10;
		}
		cout << num << endl;
	}
	cout << endl;
	return 0;
}