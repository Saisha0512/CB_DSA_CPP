#include <iostream>
using namespace std;

int main(){
	int n;
	int no;
	int i;
	cout << "Enter the limit : ";
	cin >> n;
	cout << "Following are the Prime Numbers upto the entered limit : ";
	for (no = 2; no <= n; no +=1){
		for (i = 2; i < no; i += 1){
			if (no % i == 0){
				break;
			}
		}
		if (i == no){
			cout << no << ' ';
		}
	}
	cout << endl;
	return 0;
}