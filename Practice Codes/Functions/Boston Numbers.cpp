#include <iostream>
using namespace std;

int digitsum(int num){
	int sum = 0;
	while (num != 0){
		int rem = num % 10;
		sum += rem;
		num /= 10;
	}
	return sum;
}

int checkprime(int a){
	bool ans = false;
	int i = 2;
	while (i < a){
		if (a % i == 0){
			ans = false;
			break;
		}
		i += 1;
	}
	if (i == a){
		ans = true;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int fsum = 0;
	int dsum = digitsum(n);
	for (int i = 2; i*i <= n; i ++){
		if (checkprime(i) == true && n % i == 0){
			while(n % i == 0){
				fsum += digitsum(i);
				n /= i;
			}
		}
	}
	if (n > 1){
		fsum += digitsum(n);
	}
	if (dsum == fsum){
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}