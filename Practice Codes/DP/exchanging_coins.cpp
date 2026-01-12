# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

long long sell(int n, unordered_map<long long, long long> &dp){
    // Base Case : 
    if (n == 0){
        return 0;
    }

    // Check DP : 
    if (dp.find(n) != dp.end()){
        return dp[n];
    }

    // Recursive Case : 
    long long ans = max((long long)n, sell(n/2, dp) + sell(n/3, dp) + sell(n/4, dp));

    return dp[n] = ans;
}

int main(){
    long long n;
    cin >> n;
    unordered_map<long long, long long> dp;
    
    cout << sell(n, dp) << endl;

    return 0;
}