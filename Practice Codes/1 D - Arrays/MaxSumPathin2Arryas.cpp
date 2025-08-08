#include <iostream>
using namespace std;

int maxsumpath(int a1[], int a2[], int m, int n){
    int i = 0, j = 0;
    int result = 0, sum1 = 0, sum2 = 0;
    while (i < m && j < n){
        if(a1[i] < a2[j]){
            sum1 += a1[i++];
        }
        else if(a1[i] > a2[j]){
            sum2 += a2[j++];
        }
        else{
            result += max(sum1, sum2) + a1[i];
            sum1 = 0;
            sum2 = 0;
            i ++;
            j ++;
        }
    }
    while (i < m){
        sum1 += a1[i++];
    }
    while (j < n){
        sum2 += a2[j++];
    }
    result += max(sum1, sum2);
    return result;
}

int main(){
    int t;
    cin >> t;
    for (int d = 0; d < t; d ++){
        int m, n;
        cin >> m;
        cin >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i ++){
            cin >> arr1[i];
        }
        for (int j = 0; j < n; j ++){
            cin >> arr2[j];
        }
        cout << maxsumpath(arr1, arr2, m, n) << endl;
    }
    return 0;
}