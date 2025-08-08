# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main(){
    int t;
    cin >> t;
    vector<pair<int, int>> act;
    while (t --){
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++){
            int s, e;
            cin >> s >> e;
            act.push_back({s, e});
        }
        sort(act.begin(), act.end(), compare);
        int res = 1;
        int fin = act[0].second;
        for (int i = 1; i < n; i ++){
            if (act[i].first >= fin){
                res ++;
                fin = act[i].second;
            }
        }
        cout << res << endl;
        act.clear();
    }
    return 0;
}