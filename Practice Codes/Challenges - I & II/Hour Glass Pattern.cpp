#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n <= 20){
		for (int row = 1; row <= 2*n + 1; row ++){
			if (row <= n + 1){
				for (int i = 1; i < row; i ++){
					cout << "  ";
				}
				for (int j = n - row + 1; j >= 0; j --){
					cout << j << " ";
				}
				for (int k = 1; k <= n - row + 1; k++){
					cout << k << " ";
				}
			}
			else {
				for (int l = 2*n - row + 1; l >= 1; l -- ){
					cout << "  ";
				}
				for (int m = row - n - 1; m >= 0; m --){
					cout << m << " ";
				}
				for (int p = 1; p <= row - n - 1; p ++){
					cout << p << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
}