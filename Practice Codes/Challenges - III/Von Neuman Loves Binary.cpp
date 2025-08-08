#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++){
		int a;
		cin >> a;
		int pl = 1;
		int num = 0;
		if (a == 0){
			cout << 0 << endl;
		}
		else {
			while (a != 0){
				int rem = a%10;
				num = num + rem*pow(2, pl - 1);
				pl ++;
				a /= 10;
			}
			cout << num << endl;
		}
	}
	cout << endl;
	return 0;
}