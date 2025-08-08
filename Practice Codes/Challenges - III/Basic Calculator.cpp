#include <iostream>
using namespace std;

int main(){
	char ch;
	cin >> ch;
	while (1){
		if (ch == '+'){
			int a, b;
			cin >> a;
			cin >> b;
			cout << a + b << endl;
		}
		else if (ch == '-'){
			int a,b;
			cin >> a;
			cin >> b;
			cout << a - b << endl;
		}
		else if (ch == '*'){
			int a, b;
			cin >> a;
			cin >> b;
			cout << a*b << endl;
		}
		else if (ch == '/'){
			int a, b;
			cin >> a;
			cin >> b;
			if (b == 0){
				break;
			}
			else {
				cout << a/b << endl;
			}
		}
		else if (ch == 'X' || ch == 'x'){
			break;
		}
		else {
			cout << "Invalid operation. Try again." << endl;
		}
		cin >> ch;
	}
	cout << endl;
	return 0;
}