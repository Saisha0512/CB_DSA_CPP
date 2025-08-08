# include <iostream>
#include <algorithm>
# include <set>
using namespace std;

void dictOrderLarger(string org, string &s, int i, set<string> &res){
    // Base Case : 
    if (s > org){
        res.insert(s);
    }
    if (i >= s.size()){
        return;
    }

    // Recursive Case : 
    if (i + 1 < s.size() && s[i + 1] > s[i]){
        swap(s[i + 1], s[i]);
        dictOrderLarger(org, s, i + 1, res);
    }
    else {
        dictOrderLarger(org, s, i + 1, res);
    }
}

int main(){
    string s;
    cin >> s;
    set<string> res;
    string org = s;
    dictOrderLarger(org, s, 0, res);
    for (string x : res){
        cout << x << " ";
    }
    return 0;
}