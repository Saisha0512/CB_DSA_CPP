#include <iostream>
using namespace std;

int main(){
	int n;
	int i = 2;
	cout << "Enter the required number : ";
	cin >> n;
	while (i < n){
		if (n % i == 0){
			cout << "Not a Prime Number";
			break;
		}
		i += 1;
	}
	if (i == n){
		cout << "Prime Number";
	}
	return 0;
}