#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a;
	cin >> b;
	int gcd = 1;
	if (a > b){
		for (int i = 2; i <= b; i ++){
			if (a % i == 0 && b % i == 0){
				gcd = i;
			}
		}
	}
	else if (b > a){
		for (int j = 2; j <= a; j ++){
			if (a % j == 0 && b % j == 0){
				gcd = j;
			}
		}
	}
	cout << gcd << endl;
	return 0;
}