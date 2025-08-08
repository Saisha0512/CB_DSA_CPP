#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int row, col;
	if (n % 2 != 0){
		for (row = 1; row <= n; row += 1){
			for (col = 1; col <= n; col += 1){
				if (row <= (n+1)/2){
					if (col > n - row -1 && col < n + row - 3){
						cout << " " << '\t';
					}
					else {
						cout << "*" << '\t';
					}
				}
				else if (row > (n+1)/2){
					if (col > row - n + 3 && col < n - row + 3){
						cout << " " << '\t';
					}
					else {
						cout << "*" << '\t';
					}
				}
			}
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}