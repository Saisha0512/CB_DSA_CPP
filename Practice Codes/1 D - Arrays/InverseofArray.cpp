#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int inv[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int j = 0; j < n; j ++){
        inv[a[j]] = j;
    }
    for (int k = 0; k < n; k ++){
        cout << inv[k] << " ";
    }
    cout << endl;
    return 0;       
}