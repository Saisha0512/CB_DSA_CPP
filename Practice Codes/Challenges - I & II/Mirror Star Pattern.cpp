#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n > 0 && n < 10 && n % 2 != 0){
		for(int i = 1; i <= n; i ++){
			if(i <= (n+1)/2){
				for(int j = (n+1)/2-i; j > 0; j --){
					cout << "  ";
				}
				for(int k = 1; k < 2*i; k ++){
					cout << "* ";
				}
			}

			else{
				for(int l = 1; l <= (2*i - n)/2; l ++)
					cout << "  ";
				for(int m = 2*(n - i) + 1 ; m >= 1; m --)
					cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}