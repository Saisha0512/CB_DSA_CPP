#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n > 2 && n <= 1000000000){
		for (int i = 2; i <= n; i ++){
			if (i != n){
				if (n % i == 0){
					cout << "Not Prime";
				    break;
				}
			}
			if (i == n){
				cout << "Prime";
			}
		}

	}
	else if (n == 2){
		cout << "Prime";
	}
	cout << endl;
	return 0;
}