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
	long int n;
	cin >> n;
	if(n == armstrong(n)){
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}