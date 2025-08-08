#include <iostream>
using namespace std;

int rainwater(int a[], int n){
    int res = 0;
    for (int i = 1; i < n - 1; i ++){
        int left = a[i];
        for (int j = 0; j < i; j ++){
            left = max(left, a[j]);
        }
        int right = a[i];
        for (int j = i + 1; j < n; j ++){
            right = max(right, a[j]);
        }
        res += (min(left, right) - a[i]);
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        int n; 
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j ++){
            cin >> arr[j];
        }
        cout << rainwater(arr, n) << endl;
    }
    return 0;
}