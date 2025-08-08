# include <iostream>
using namespace std;

int idx[100] = {0};
int k = 0;

void InsertIndices(int arr[], int n, int i, int key){
    if (i == n){
        return;
    }
    if (arr[i] == key){
        idx[k++] = i;
    }
    InsertIndices(arr, n, i + 1, key);
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
    InsertIndices(arr, n, 0, m);
    for (int i = 0; i < k; i ++){
        cout << idx[i] << " ";
    }
    return 0;
}