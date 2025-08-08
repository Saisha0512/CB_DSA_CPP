#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "Number of Even Numbers to be printed :";
	cin >> n;
	int a = 2;
	int i = 1;
	cout << "Following are the required Even Numbers : " << '\n';
	while (i <= n){
		cout << a << ' ';
		a += 2;
		i += 1;
	}
	return 0;

}