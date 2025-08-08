# include <iostream>
using namespace std;

int FirstIndex(int arr[], int n, int i, int key){
    if (i == n){
        return -1;
    }
    if (arr[i] == key){
        return i;
    }
    int j = FirstIndex(arr, n, i + 1, key);
    if (j == -1){
        return -1;
    }
    return j;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << FirstIndex(arr, n, 0, m) << endl;
    return 0;
}