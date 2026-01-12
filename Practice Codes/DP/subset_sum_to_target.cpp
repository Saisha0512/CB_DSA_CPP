# include <iostream>
# include <vector>
using ll = long long;
using namespace std;

// BOTTOM UP CODE : 
int main(){
    int n;
    cin >> n;
    ll target;
    cin >> target;
    vector<ll> arr(n);
    for (auto &it : arr)    cin >> it;

    vector<vector<int>> dp(n, vector<int> (target + 1, 0));

    // Base Cases : 
    // Case 1 : If the target becomes 0, at any index
    for (int i = 0; i < n; i ++){
        dp[i][0] = 1;
    }
    if (arr[0] <= target){
        dp[0][arr[0]] = 1;
    }

    // Bottom up loop : 
    for (int i = 1; i < n; i ++){
        for (int j = 1; j <= target; j ++){
            // Case 1 : Not taking the current element
            int notTaken = dp[i - 1][j];

            // Case 2 : 
            int taken = 0;
            if (arr[i] <= j){
                taken = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = (taken || notTaken);
        }
    }

    if (dp[n - 1][target]){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}