#include <iostream>
#include <climits>
using namespace std;

int main(){
	int largest = INT_MIN;
	for(int i = 1; i <= 5; i ++){
		int n;
		cin >> n;
		if (largest < n){
			largest = n;
		}
	}
	cout << largest;
	return 0;
}