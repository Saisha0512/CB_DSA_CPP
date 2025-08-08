# include <iostream>
using namespace std;

void merge(int *a, int *b, int *c, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    while(i <= mid && j <= e){
        if (b[i] <= c[j]){
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i <= mid){
        a[k++] = b[i++];
    }
    while (j <= e){
        a[k ++] = c[j++];
    }
}

void MergeSort(int *a, int s, int e){
    if (s >= e){
        return;
    }
    int mid = (s+e)/2;
    int b[100], c[100];
    for (int i = 0; i <= mid; i ++){
        b[i] = a[i];
    }
    for (int i = mid+1; i <= e; i ++){
        c[i] = a[i];
    }
    MergeSort(b, s, mid);
    MergeSort(c, mid+1, e);
    merge(a, b, c, s, e);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    return 0;
}