#include<iostream>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int num = 0;
    long long int pl = 1;
    while(n != 0){

      long long int rem = n % 10;

      if(rem >= 5){
        if(rem == 9 && (n/10) == 0){
        }
        else{
          rem = 9 - rem;
        }
      }
      num += rem * pl;
      pl *= 10;
      n /= 10;
    }
    cout << num << endl;
    return 0;
}