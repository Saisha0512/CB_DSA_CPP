# include <iostream>
# include <set>
# include <string>
using namespace std;

void dictOrderSmaller(string org, int i, string &s, set<string> &res){
    // Base Case : 
    if (i >= s.size()){
        if (s < org){
            res.insert(s);
        }
        return;
    }

    // Recursive Case : 
    for (int j = i; j < s.size(); j ++){
        swap(s[i], s[j]);
        dictOrderSmaller(org, i + 1, s, res);
        swap(s[i], s[j]); // Backtracking
    }
}

int main(){
    string s;
    cin >> s;
    string org = s;
    set<string> res;
    dictOrderSmaller(org, 0, s, res);
    for (string x : res){
        cout << x << endl;
    }
    return 0;
}