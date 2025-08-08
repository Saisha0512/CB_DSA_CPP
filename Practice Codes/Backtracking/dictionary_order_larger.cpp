# include <iostream>
#include <algorithm>
# include <set>
using namespace std;

void dictOrderLarger(string org, string &s, int i, set<string> &res){
    // Base Case : 
    if (i >= s.size()){
        if (s > org){
            res.insert(s);
        }
        return;
    }

    // Recursive Case : 
    // Try all options at position i
    for (int j = i; j < s.size(); j ++){
        swap(s[i], s[j]);
        dictOrderLarger(org, s, i + 1, res);
        swap(s[i], s[j]); // Backtracking
    }
}

int main(){
    string s;
    cin >> s;
    set<string> res;
    string org = s;
    dictOrderLarger(org, s, 0, res);
    for (string x : res){
        cout << x << endl;
    }
    return 0;
}