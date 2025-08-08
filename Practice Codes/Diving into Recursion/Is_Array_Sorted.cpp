# include <iostream>
using namespace std;

bool IsArraySorted(int arr[], int i, int n){
    if(i == n){
        return true;
    }

    return (arr[i] <= arr[i+1] && IsArraySorted(arr, i + 1, n));
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    if (IsArraySorted(arr, 0, n)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}