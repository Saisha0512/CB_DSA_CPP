#include <iostream>
using namespace std;

int main() {
	int n; 
	cin >> n;
	if (n <= 10){
		for (int row = 1; row <= n; row ++){
			int num = 1;
			for (int i = n - row; i >= 1; i --){
				cout << "  ";
			}
			for (int j = 1; j <= row; j ++){
				if (j == 1){
					cout << " " << 1 << "   ";
				}
				else if (j == row){
					cout << 1 << " ";
				}
				else {
					num = num*(row - j + 1)/(j - 1);
					cout << num << "   ";
				}
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
}