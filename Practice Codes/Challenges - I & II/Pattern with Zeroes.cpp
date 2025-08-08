#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int row, col;
	for (row = 1; row <= n; row += 1){
		for (col = 1; col <= row; col += 1){
			if (col == 1 || col == row){
				cout << row << '\t';
			}
			else {
				cout << "0" << '\t';
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}