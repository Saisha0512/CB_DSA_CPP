#include <iostream>
using namespace std;

int main(){
	int sum = 0, num;
	while (sum >= 0){
		cin >> num;
		sum = sum + num;
		if (sum < 0){
			break;
		}
		cout << num << endl;
	}
	cout << endl;
	return 0;
}