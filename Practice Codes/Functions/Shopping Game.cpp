#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	int largest = 0;
	for (int a = 1; a <= t; a ++){
		long long int m, n;
		cin >> m;
		cin >> n;
		long long int i = 1;
		long long int j = 2;
		m -= i;
		n -= j;
		while (true){
			if(m < 0){
				cout << "Harshit" << endl;
				break;
			}
			else if (n < 0){
				cout << "Aayush" << endl;
				break;
			}
			i += 2;
			j += 2;
			m -= i;
			n -= j;
		}
	}
	return 0;
}