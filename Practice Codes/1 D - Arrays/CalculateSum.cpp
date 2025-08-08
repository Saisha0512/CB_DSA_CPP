#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    int temp[n];
    for (int j = 0; j < q; j ++){
        int x;
        cin >> x;
        for (int k = 0; k < n; k ++){
            temp[k] = a[k] + a[(k - x + n)%n];
        }
        for (int l = 0; l < n; l ++){
            a[l] = temp[l];
        }
    }
    int sum = 0;
    for (int b = 0; b < n; b ++){
        sum += a[b];
    }
    cout << sum << endl;
    return 0;
}