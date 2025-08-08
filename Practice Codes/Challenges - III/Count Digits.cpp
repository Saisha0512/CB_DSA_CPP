#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int num;
	cin >> num;
	int count = 0;
	while (n != 0){
		int rem = n%10;
		if (rem == num){
			count ++;
		}
		n = n/10;
	}
	cout << count << endl;
	return 0;
}