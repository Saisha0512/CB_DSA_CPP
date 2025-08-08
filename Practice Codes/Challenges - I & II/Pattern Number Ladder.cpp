#include <iostream>
using namespace std;

int main(){
	int n;
	int i = 1;
	cin >> n;
	int row, col;
	for (row = 1; row <= n; row += 1){
		for (col = 1; col <= row; col += 1){
			cout << i << '\t';
			i += 1;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}