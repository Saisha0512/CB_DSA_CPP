#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    if (n > 0){
        int a[n];
        int rev[n];
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }
        for (int j = 0; j < n; j ++){
            rev[j] = a[n - j - 1];
        }
        for (int k = 0; k < n; k ++){
            cout << rev[k] << endl;
        }
        cout << endl;
    }
    return 0;
}