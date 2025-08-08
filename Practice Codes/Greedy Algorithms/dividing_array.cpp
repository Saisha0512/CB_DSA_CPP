# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long maxans = 0;
        int i = 0, j = n/2;
        while (i < n && j < n){
            maxans += abs(arr[i] - arr[j]);
            i ++;
            j ++;
        }
        long long minans = 0;
        i = 0;
        j = 1;
        while (i < n && j < n){
            minans += abs(arr[j] - arr[i]);
            i += 2;
            j += 2;
        }
        cout << minans << " " << maxans << endl;
    }
    return 0;
}