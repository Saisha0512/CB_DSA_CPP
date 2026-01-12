# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using ll = long long;
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        
        vector<ll> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i ++){
            ll next2 = dp[p2] * 2;
            ll next3 = dp[p3] * 3;
            ll next5 = dp[p5] * 5;

            ll ugly = min(next2, min(next3, next5));
            dp[i] = ugly;

            if (ugly == next2)  p2 ++;
            if (ugly == next3)  p3 ++;
            if (ugly == next5)  p5 ++;
        }

        cout << dp[n - 1] << endl;
    }

    return 0;
}