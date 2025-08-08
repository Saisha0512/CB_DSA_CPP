#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n % 2 != 0){
		for (int row = 1; row <= n; row ++){
			int a = (n+1)/2;
			if (row <= a){
				for (int i = a - row; i >= 1; i --){
					cout << "    ";
				}
				for (int j = row; j >= 1; j --){
					cout << j << " ";
				}
				for (int k = 1; k <= 2*row - 3; k ++){
					cout << "  ";
				}
				if (row != 1){
					for (int l = 1; l <= row; l ++){
						cout << l << " ";
					}
				}
			}
			else if (row > a && row <= n){
				for (int m = 1; m <= row - a; m ++){
					cout << "    ";
				}
				for (int p = 2*a - row; p > 0; p --){
					cout << p << " ";
				}
				for (int q = 2*(n - row) - 1; q >= 1; q --){
					cout << "  ";
				}
				if (row != n){
					for (int r = 1; r < n - row + 2; r ++){
						cout << r << " ";	
				    }
				}
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
} 