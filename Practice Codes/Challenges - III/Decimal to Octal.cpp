#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int count = 1;
	int num = 0;
	while (n != 0){
		int rem = n%8;
		num = num + rem*count;
		count *= 10;
		n = n/8;
	}
	cout << num << endl;
	return 0;
}