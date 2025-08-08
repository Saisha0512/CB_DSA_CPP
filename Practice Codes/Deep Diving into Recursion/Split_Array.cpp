# include <iostream>
using namespace std;

void splitArray(int arr[], bool taken[], int n, int &cnt, int i, int sum){
    // Base Case :
    if (i == n){
        int total = 0;
        for (int a = 0; a < n; a ++){
            if (taken[a] == true){
                total += arr[a];
            }
        }
        if (total == sum){
            for (int j = 0; j < n; j ++){
                if (taken[j] == true){
                    cout << arr[j] << " ";
                }
            }
            cout << "and ";
            for (int k = 0; k < n; k ++){
                if (taken[k] == false){
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
            cnt ++;
        }
        return;
    }

    // Recursive Case :
    taken[i] = true;
    splitArray(arr, taken, n, cnt, i + 1, sum);
    taken[i] = false;
    splitArray(arr, taken, n, cnt, i + 1, sum);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    bool taken[n];
    int sum = 0;
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        taken[i] = false;
    }
    if (sum % 2 != 0){
        cout << "0" << endl;
        return 0;
    }
    sum /= 2;
    int cnt = 0;
    splitArray(arr, taken, n, cnt, 0, sum);
    cout << cnt << endl;
    return 0;
}