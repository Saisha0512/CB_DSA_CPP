#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the required number : ";
	cin >> n;
	int row;
	int i, j;
	for (row = 1; row <= n; row += 1){
		for (i = 1; i <= (n - row); i += 1){
			cout << "  ";
		}
		for (j = 1; j <= (2*row - 1); j += 1){
			cout << j << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return 0;

}