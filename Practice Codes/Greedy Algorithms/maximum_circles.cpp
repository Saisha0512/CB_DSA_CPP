# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2){
    return p1.second < p2.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i ++){
        int c, r;
        cin >> c >> r;
        arr.push_back({c - r, c + r});
    }
    sort(arr.begin(), arr.end(), compare);
    int e = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i ++){
        if (arr[i].first >= e){
            ans ++;
            e = arr[i].second;
        }
    }
    cout << n - ans << endl;
    return 0;
}