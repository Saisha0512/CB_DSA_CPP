#include <iostream>
using namespace std;

int main(){
	string s1;
	cin >> s1;
	for (int i = 0; i < s1.size(); i ++){
		if (s1[i] == '0'){
			s1[i] = '5';
		}
	}
	cout << s1 << endl;
	return 0;
}
