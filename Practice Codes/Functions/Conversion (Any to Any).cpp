#include <iostream>
#include <math.h>
using namespace std;

int anytodecimal(int base, long long int a){
	long long int ans = 0;
	long long int pl = 1;
	while (a != 0){
		int rem = a % 10;
		ans += rem*pow(base, pl - 1);
		pl ++;
		a /= 10;
	}
	return ans;
}

int decimaltoany(int base, long long int m){
	long long int ans = 0;
	long long int pl = 1;
	while (m != 0){
		int rem = m % base;
		ans += rem*pl;
		pl *= 10;
		m /= base;
	}
	return ans;
}

int main(){
	int sb, db;
	long long int sn;
	cin >> sb;
	cin >> db;
	cin >> sn;
	long long int deci = anytodecimal(sb, sn);
	long long int ans = decimaltoany(db, deci);
	cout << ans << endl;
	return 0;
}