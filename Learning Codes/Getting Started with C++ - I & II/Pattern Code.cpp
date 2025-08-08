#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the required number : ";
	cin >> n;
	int row, col;
	for (row = 1; row <= n; row += 1){
		for (col = 1; col <= row; col += 1){
			cout << '*' << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}