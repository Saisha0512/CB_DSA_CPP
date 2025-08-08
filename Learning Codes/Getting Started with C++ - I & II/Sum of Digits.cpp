#include <iostream>
using namespace std;

int main(){
	int n;
	int sum = 0;
	cout << "Enter the Number : ";
	cin >> n;
	while(n != 0){
		sum = sum + n % 10;
		n = n / 10;
	}
	cout << "Required Sum is : " << sum;
	return 0;
}