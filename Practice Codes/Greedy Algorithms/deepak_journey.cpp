# include <iostream>
# include <vector>
# include <climits>
using namespace std;

int main(){
    int t;
    cin >> t; 
    while (t --){
        int n;
        cin >> n;
        vector<long long> c(n);
        vector<long long> l(n);
        for (int i = 0; i < n; i ++){
            cin >> c[i];
        }
        for (int i = 0; i < n; i ++){
            cin >> l[i];
        }
        long long mincost = c[0];
        long long currcost = c[0]*l[0];
        for (int i = 1; i < n; i ++){
            if (c[i] < mincost){
                mincost = c[i];
            }
            currcost += (mincost * l[i]);
        }
        cout << currcost << endl;
    }
    return 0;
}