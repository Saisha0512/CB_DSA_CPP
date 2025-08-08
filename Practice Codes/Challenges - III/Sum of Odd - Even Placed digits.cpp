#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int esum = 0;
	int osum = 0;
	int pl = 1;
	while (n != 0){
		int rem = n%10;
		if (pl%2 != 0){
			osum += rem;
		}
		else if (pl%2 == 0){
			esum += rem;
		}
		pl ++;
		n = n/10;
	}
	cout << osum << endl;
	cout << esum << endl;
	return 0;
}