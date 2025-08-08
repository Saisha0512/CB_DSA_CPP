#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool ans = true;
	bool dec = true;
	int pre;
	cin >> pre;
	for (int i = 1; i < n; i ++){
		int curr;
		cin >> curr;
		if (curr == pre){
			ans = false;
			break;
		}
		else if (curr > pre){
			dec = false;
		}
		else if (dec == false && curr < pre){
			ans = false;
			break;
		}
		pre = curr;
	}
	if(ans){
		cout << "true" << endl; 
	}
	else {
		cout << "false" << endl;
	}
	cout << endl;
	return 0;
}