#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	if (n > 0 && n < 10){
		for (int row = 1; row <= n; row ++){
			int num = 1;
			for (int col = 1; col <= row; col ++){
				if (col == 1 || col == row){
					cout << 1 << '\t';
			    }
			    else {
			    	num = num*(row - col + 1)/(col - 1);
				    cout << num << '\t';
			    }
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
}