#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;
	int lcm = 0;
	if (a > b){
		lcm = a;
		while (lcm >= a){
			if (lcm % a == 0 && lcm % b == 0){
				break;
			}
			lcm ++;
		}
	}
	else if (b > a){
		lcm = b;
		while (lcm >= b){
			if (lcm % a == 0 && lcm % b == 0){
				break;
			}
			lcm ++;
		}
	}
	else if (a == b){
		lcm = a;
	}
	cout << lcm << endl;
	return 0;
}