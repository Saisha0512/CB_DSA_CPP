# include <iostream>
# include <vector>
# include <climits>
using ll = long long;
using namespace std;

ll checkWeight(vector<ll> &val, int idx, int weight, vector<vector<ll>> &dp){
    // Base Case : 
    if (weight == 0){
        return 0;
    }
    if (idx < 0){
        return LLONG_MAX;
    }

    // Check DP : 
    if (dp[idx][weight] != -1){
        return dp[idx][weight];
    }

    // Recursive Case : 
    // Case 1 : Not taking the current orange 
    ll notTaken = checkWeight(val, idx - 1, weight, dp);

    // Case 2 : Taking the current orange 
    ll taken = LLONG_MAX;
    if (idx + 1 <= weight && val[idx] != -1){
        taken = val[idx] + checkWeight(val, idx, weight - (idx + 1), dp);
    }

    return dp[idx][weight] = min(notTaken, taken);
}

int main(){
    ll n, w;
    cin >> n >> w;

    vector<ll> val(w);
    for (int i = 0; i < w; i ++){
        cin >> val[i];
    }

    ll cost = LLONG_MAX;
    vector<vector<ll>> dp(w, vector<ll>(w + 1, -1));

    ll ans = checkWeight(val, w - 1, w, dp);

    cout << ((ans == LLONG_MAX)? -1 : ans) << endl;
    
    return 0;
}