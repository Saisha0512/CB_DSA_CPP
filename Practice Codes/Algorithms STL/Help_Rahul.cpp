# include <iostream>
# include <algorithm>
using namespace std;

int findNumber(int arr[], int n, int m){
    int idx = - 1;
    if (binary_search(arr, arr + n, m) == true){
        idx = find(arr, arr + n, m) - arr;
    }
    return idx;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << findNumber(arr, n, k) << endl;
    return 0;
}