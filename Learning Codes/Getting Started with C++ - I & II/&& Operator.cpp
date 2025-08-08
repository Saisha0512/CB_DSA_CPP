#include <iostream>
using namespace std;

int main(){
	int a;
	cout << "Enter the required value : ";
	cin >> a;

	if (a >= 0 && a <= 10){
		cout <<"Hello!" << '\n';
	}
	else if (a > 10 && a<= 20){
		cout << "World!" << '\n';
	}
	else {
		cout << "Welcome to Coding Blocks!" << '\n';
	}
	return 0;
}