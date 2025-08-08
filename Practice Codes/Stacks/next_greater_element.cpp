# include <iostream>
# include <stack>
using namespace std;

void next_greater_element(int result[], int arr[], int n){
    stack<int> s;
    for (int i = 0; i < n; i ++){
        int nge = -1;
        s.push(arr[i]);
        int j = i + 1;
        while (j < n){
            if (arr[j] > s.top()){
                nge = arr[j];
                break;
            }
            j ++;
        }
        result[i] = nge;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int result[n];
    next_greater_element(result, arr, n);
    for (int i = 0; i < n; i ++){
        cout << result[i] << " ";
    }

    return 0;
}