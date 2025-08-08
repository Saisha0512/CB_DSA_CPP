#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the Range to print Even Numbers : ";
	cin >> n;
	int a = 2;
	cout << "Following are the required numbers : " << '\n';
	while (a <= n){
		cout << a << ' ';
		a += 2;
	}
	return 0;
}