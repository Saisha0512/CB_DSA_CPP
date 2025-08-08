# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first > p2.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> dest;
    for (int i = 0; i < n; i ++){
        int d, f;
        cin >> d >> f;
        dest.push_back({d, f});
    }
    int l, p;
    cin >> l >> p;
    for (auto &pr : dest){
        pr.first = l - pr.first;
    }
    sort(dest.begin(), dest.end());

    priority_queue<int> pq;
    int ans = 0;
    int prev = 0, x = 0, flag = 0;
    while (x < n){
        if (p >= (dest[x].first - prev)){
            pq.push(dest[x].second);
            p = p - (dest[x].first - prev);
            prev = dest[x].first;
        }
        else {
            if (pq.empty()){
                flag = 1;
                break;
            }

            p += pq.top();
            pq.pop();
            ans ++;
            continue;
        }
        x ++;
    }

    if (flag == 1){
        cout << -1 << endl;
        return 0;
    }

    l = l - prev;
    if (p >= l){
        cout << ans << endl;
        return 0;
    }
    while (p < l){
        if (pq.empty()){
            flag = 1;
            break;
        }
        p += pq.top();
        pq.pop();
        ans ++;
    }

    if (flag == 1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}