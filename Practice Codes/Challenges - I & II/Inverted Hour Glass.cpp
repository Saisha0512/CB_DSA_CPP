#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int row = 1; row <= 2*n + 1; row ++){
		if (row <= n){
			for (int i = n; i >= n - row + 1; i --){
				cout << i << " ";
			}
			for (int j = 2*(n - row) + 1; j >= 1; j --){
				cout << "  ";
			}
			for (int k = n - row + 1; k <= n; k ++){
				cout << k << " ";
			}
		}
		else if (row == n + 1){
			for (int l = n; l >= 0; l --){
				cout << l << " ";
			}
			for (int m = 1; m <= n; m ++){
				cout << m << " ";
			}
		}
		else if (row > n + 1){
			for (int p = n; p > row - n - 2; p --){
				cout << p << " ";
			}
			for (int q = 1; q <= 2*(row - n) - 3; q ++){
				cout << "  ";
			}
			for (int r = row - n - 1; r <= n; r ++){
				cout << r << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}