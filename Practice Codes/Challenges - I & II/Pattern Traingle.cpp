#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int row, col;
	if (n < 10){
		for (row = 1; row <= n; row += 1){
			for (col = 1; col < 2*n; col += 1){
				if (col == n - row + 1 || col == n + row - 1){
					cout << row << '\t';
			    }
			    else if (col > n - row + 1 && col <=n){
				    cout << row + (col - n + row - 1) << '\t';
			    }
			    else if (col > n && col < n + row - 1){
				    cout << row + (n + row - 1 - col) << '\t';
			    }
			    else {
			    	cout << " " << '\t';
			    }
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
	else {
		return 0;
	}	
}