# include <iostream>
# include <vector>
# include <algorithm>
using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;

// TOP - DONW APPROACH : 
// ll changeMoney(vector<int> &coins, int i, int amt, vector<vector<ll>> &dp){
//     // Base Case : 
//     if (amt == 0){
//         return 1;
//     }
//     if (amt < 0 || i == coins.size()){
//         return 0;
//     }

//     // Check DP : 
//     if (dp[i][amt] != -1){
//         return dp[i][amt];
//     }

//     // Recursive Case : 
//     // Case 1 : Skip the current coin 
//     ll ans1 = changeMoney(coins, i + 1, amt, dp);

//     // Case 2 : Take the current coin 
//     ll ans2 = 0;
//     if (coins[i] <= amt){
//         ans2 = changeMoney(coins, i, amt - coins[i], dp);
//     }

//     return dp[i][amt] = (ans1 + ans2) % mod;
// }

// dp[i][amt] = Ways to make amt using coins[i... n - 1]

int main(){
    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        vector<int> coins(n);
        for (auto &it : coins)    cin >> it;

        sort(coins.begin(), coins.end());

        int amt;
        cin >> amt;

        if (n == 0){
            cout << (amt == 0) << endl;
            continue;
        }

        vector<vector<ll>> dp(n, vector<ll>(amt + 1, 0));

        // i : Index of the coin to be considered in the current amount
        // j : Amt leftover
        // dp[i][j] : No of ways to make change of j amount using the coins at the index 0...i

        // Base Cases :
        // Case 1 : If amt == 0, then at any index dp[i][amt] = 1
        for (int i = 0; i < n; i ++){
            dp[i][0] = 1;
        }


        // Bottom up loop : 
        for (int i = 0; i < n; i ++){
            for (int j = 1; j <= amt; j ++){
                // Case 1 : Skipping the current coin
                ll ans1 = (i > 0)? dp[i - 1][j] : 0;

                // Case 2 : Taking the current coin
                ll ans2 = 0;
                if (coins[i] <= j){
                    ans2 = dp[i][j - coins[i]];
                }

                dp[i][j] = (ans1 + ans2) % mod;
            }
        }
        
        cout << dp[n - 1][amt] << endl;
    }

    return 0;
}