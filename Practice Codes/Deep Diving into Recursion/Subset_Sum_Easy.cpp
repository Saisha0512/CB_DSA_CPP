# include <iostream>
using namespace std;

bool subsets(int arr[], int n, int i, int sum, int cnt){
    // Base Case : 
    if (i == n){
        if (sum == 0 && cnt > 0){
            return true;
        }
        else {
            return false;
        }
    }

    // Recursive Case :
    bool ans1 = subsets(arr, n, i + 1, sum + arr[i], cnt + 1);
    bool ans2 = subsets(arr, n, i + 1, sum, cnt);

    return ans1 || ans2;
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        if (subsets(arr, n, 0, 0, 0)){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}