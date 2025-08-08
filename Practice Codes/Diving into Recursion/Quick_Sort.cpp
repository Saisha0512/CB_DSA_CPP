# include <iostream>
using namespace std;

int Partition(int *a, int s, int e){
    int i = s - 1;
    for (int j = s; j < e; j ++){
        if (a[j] <= a[e]){
            i ++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[e]);
    return i + 1;
}

void QuickSort(int *a, int s, int e){
    if (s >= e){
        return;
    }
    int idx = Partition(a, s, e);
    QuickSort(a, s, idx - 1);
    QuickSort(a, idx + 1, e);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    return 0;
}