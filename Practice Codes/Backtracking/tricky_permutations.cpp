# include <iostream>
# include <set>
using namespace std;

void trickyPermutation(string &s, int i, set<string> &res){
    // Base Case : 
    if (i == s.size()){
        res.insert(s);
    }

    // Recursive Case : 
    for (int j = i; j < s.size(); j ++){
        swap(s[i], s[j]);
        trickyPermutation(s, i + 1, res);
        swap(s[i], s[j]);
    }
}

int main(){
    string s;
    cin >> s;
    set<string> res;
    trickyPermutation(s, 0, res);
    for (string x : res){
        cout << x << endl;
    }
    return 0;
}