#include <iostream>
using namespace std;

void Final(int evensum, int oddsum){
	if (evensum % 4 == 0 || oddsum % 3 == 0){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++){
		int num;
		cin >> num;
		int esum = 0, osum = 0;
		while (num != 0) {
			int rem = num % 10;
			if (rem % 2 == 0){
				esum += rem;
			}
			else {
				osum += rem;
			}
			num /= 10;
		}
		Final (esum, osum);
	}
	return 0;
}