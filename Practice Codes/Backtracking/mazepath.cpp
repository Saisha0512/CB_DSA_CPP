# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void mazepath(int n, int m, int i, int j, int &cnt, string &curr, vector<string> &res){
    // Base Case : 
    if (i == n - 1 && j == m - 1){
        res.push_back(curr);
        cnt ++;
        return;
    }

    // Recursive Case : 
    // Move Down : 
    if (i + 1 < n){
        curr.push_back('V');
        mazepath(n, m, i + 1, j, cnt, curr, res);
        curr.pop_back();
    }

    // Move Right : 
    if (j + 1 < m){
        curr.push_back('H');
        mazepath(n, m, i, j + 1, cnt, curr, res);
        curr.pop_back();
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    string curr = "";
    vector<string> res;
    mazepath(n, m, 0, 0, cnt, curr, res);
    sort(res.begin(), res.end(), greater<string>());
    for (string s : res){
        cout << s << " ";
    }
    cout << endl << cnt << endl;
    return 0;
}