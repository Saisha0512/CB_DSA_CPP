#include <iostream>
#include <climits>
using namespace std;

int MaxValueArray(int a[], int len){
    int max = INT_MIN;
    for (int j = 0; j < len; j ++){
        if (max < a[j]){
            max = a[j];
        }
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    int a[1000];
    if (n > 0){
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }
        cout << MaxValueArray(a, n) << endl;
    }
    return 0;
}