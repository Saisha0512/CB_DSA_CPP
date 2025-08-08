#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the limit of numbers to be printed : ";
	cin >> n;
	int a = 1;
	cout << "Following are the numbers from 1 to 10 : " << '\n'; 
	while (a <= n){
		cout << a << ' ';
		a += 1;
	}
	return 0;
}