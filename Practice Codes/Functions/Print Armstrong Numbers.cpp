#include <iostream>
#include <math.h>
using namespace std;

int count(long int num){
	int count = 0;
	do{
		num /= 10;
		count ++;
	} while (num != 0);
	return count;
}

int armstrong(long int a){
	int dig = count(a);
	long int arm = 0;
	while (a != 0){
		int rem = a % 10;
		arm += pow(rem, dig);
		a /= 10;
	}
	return arm;
}

int main(){
	long int n1, n2;
	cin >> n1;
	cin >> n2;
	for (int i = n1; i <= n2; i ++){
		if (i == armstrong(i)){
			cout << i << endl;
		}
	}
	return 0;
}