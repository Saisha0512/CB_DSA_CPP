# include <iostream>
using namespace std;

int LastIndex(int arr[], int n, int i, int key){
    if (i == n){
        return -1;
    }
    if (arr[i] == key){
        int j = LastIndex(arr, n, i + 1, key);
        if (j == -1){
            return i;
        }
        else {
            return j;
        }
    }
    return LastIndex(arr, n, i + 1, key);
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
    cout << LastIndex(arr, n, 0, m) << endl;
    return 0;
}