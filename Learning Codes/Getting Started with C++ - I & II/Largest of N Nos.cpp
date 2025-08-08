#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n;
	int largest = INT_MIN;
	int i =1;
	int no;
	cout << "Enter the limit of numbers to be checked : ";
	cin >> n;
	while(i <= n){
		cout << "Enter the Required Number" << i << " : ";
		cin >> no;
		if(largest < no){
			largest = no;
		}
		i += 1;
	}
	cout << "Largest Number is : " << largest;
	cout << endl;
	return 0;
}