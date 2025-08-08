# include <iostream>
# include <vector>
# include <map>
using namespace std;

void countFreq(vector<int> arr1, vector<int> arr2, map<int, pair<int, int>> &m){
    for (int i = 0; i < arr1.size(); i ++){
        int a = arr1[i], b = arr2[i];
        m[a].first ++;
        m[b].second ++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i ++){
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> arr2[i];
    }
    // Map : <value, <freq in arr1, freq in arr2>>
    map<int, pair<int, int>> m;
    countFreq(arr1, arr2, m);
    vector<int> ans;
    for (auto p : m){
        if (p.second.first > 0 && p.second.second > 0){
            for (int i = 0; i < min(p.second.first, p.second.second); i ++){
                ans.push_back(p.first);
            }
        }
    }

    // Printing ans vector
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i ++){
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size() - 1] << "]";
    return 0;
}
