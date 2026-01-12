# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using ll = long long;
using namespace std;

ll pairing(vector<ll> &boys, vector<ll> &girls, int i, int j, vector<vector<ll>> &dp){
    // Base Case : 
    if (i < 0){ // No boy is left
        return 0;
    }
    if (j < 0){ // Boys > Girls
        return LLONG_MAX;
    }
    if (i > j){
        return LLONG_MAX;
    }

    // Check DP : 
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    // Recursive Case : 
    // Case 1 : Not pairing the ith boy with the jth girl : 
    ll notTaken = pairing(boys, girls, i, j - 1, dp);

    // Case 2 : Pairing the ith boy with the jth girl : 
    ll taken = LLONG_MAX;
    ll next = pairing(boys, girls, i - 1, j - 1, dp);
    if (next != LLONG_MAX){
        taken = abs(boys[i] - girls[j]) + next;
    }

    return dp[i][j] = min(notTaken, taken);
}

// dp[i][j] = min cost to match first i boys using the first j girls

int main(){
    int n, m;
    cin >> n >> m;
    // n : No of boys
    // m : No of girls
    vector<ll> boys(n), girls(m);
    for (auto &it : boys)   cin >> it;
    for (auto &it : girls)  cin >> it;

    // Sorting both the arrays : 
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    vector<vector<ll>> dp(n, vector<ll>(m, -1));

    pairing(boys, girls, n - 1, m - 1, dp);

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}