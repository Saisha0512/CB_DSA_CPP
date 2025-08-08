#include <iostream>
using namespace std;

int main() {
	int min, max, step;
	cin >> min;
	cin >> max;
	cin >> step;
	for (int f = min; f <= max; f += step){
		int cel = 0;
		cel = (5/9.0)*(f - 32);
		cout << f << '\t' << cel << endl;
	}
	cout << endl;
	return 0;
}
