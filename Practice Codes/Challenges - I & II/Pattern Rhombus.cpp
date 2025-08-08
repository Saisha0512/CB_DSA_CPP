#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int row;
	int a = 2*n;
	if (n > 0 && n < 10){
		for (row = 1; row < a; row ++){
			if (row <= n){
				for (int i = n - row; i >= 1; i --){
					cout << " " << '\t';
				}
				for (int j = 1; j < 2*row; j ++){
					if (j <= row){
						cout << row + j - 1 << '\t';
					}
					else if (j > row){
						cout << row + (2*row - 1 -j)  << '\t';
					}
				}
			}
			else if (row > n){
				for (int k = 1; k < row - n + 1; k ++){
					cout << " " << '\t';
				}
				for (int l = 2*(a - row) - 1; l >= 1; l --){
					if (l >= a - row){
						cout << a - row + 2*(a - row) - 1 - l << '\t';
					}
					else if (l < a - row){
						cout << a - row + l - 1 << '\t';
					}
				}
			} 
			cout << endl;
		}
		cout << endl;
		return 0;
	}
}