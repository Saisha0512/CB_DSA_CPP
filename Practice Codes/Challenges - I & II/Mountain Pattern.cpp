#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n > 0 && n < 10){
		for (int row = 1; row <= n; row ++){
			for (int i = 1; i <= row; i ++){
				cout << i << '\t';
			}
			for (int j = 1; j <= 2*(n - row) - 1; j ++){
				cout << " " << '\t';
			}
			if (row < n){
				for (int k = row; k >= 1; k --){
					cout << k << '\t';
			    }
			}
			else if (row == n){
				for (int k = row - 1; k >= 1; k --){
					cout << k << '\t';
			    }
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
}