#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 0;
	int b = 1;
	int c;
	int row, col;
	for (row = 1; row <= n; row += 1){
		for (col = 1; col <= row; col += 1){
			if (row == 1 && col == 1){
				cout << a << '\t';
			}
			else if (row == 2 && col == 1){
				cout << b << '\t';
			}
			else {
				c = a + b;
				cout << c << '\t';
				a = b;
				b = c;
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}