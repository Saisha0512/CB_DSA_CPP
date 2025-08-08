#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int row, col;
	for (row = 1; row < 2*n; row += 1){

		for (col = 1; col < 2*n; col += 1){

			if (row >= 1 && row <=n){
				if (col > n - row + 1 && col < n + row - 1){
					cout << " ";
				}
				else {
					cout << "*";
				}
			}
			else if (row > n && row < 2*n){
				if (col > row - n + 1 && col < 2*n - row + n - 1){
					cout << " ";
				}
				else {
					cout << "*";
				}
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}