# include <iostream>
# include <climits>
# include <string>
# include <unordered_map>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (s1.size() < s2.size()){
        cout << "No String" << endl;
        return 0;
    }
    unordered_map<char, int> freq;
    for (char x : s2){
        freq[x] ++;
    }

    unordered_map<char, int> temp;
    int start = 0, ans = INT_MAX, matched = 0;
    int minStart = 0;
    for (int i = 0; i < s1.size(); i ++){
        temp[s1[i]] ++;

        // Only if character is part of s2 and frequency is within limit
        if (freq.count(s1[i]) && temp[s1[i]] <= freq[s1[i]]){
            matched ++;
        }

        // Try to shrink the window
        while (matched == s2.length()){
            if (i - start + 1 < ans){
                ans = i - start + 1;
                minStart = start;
            }

            char startChar = s1[start];
            temp[startChar] --;

            if (freq.count(startChar) && temp[startChar] < freq[startChar]){
                matched --;
            }
            start ++;
        }
    }

    string res = "";
    if (ans == INT_MAX){
        cout << "No String" << endl;
        return 0;
    }
    else{
        res = s1.substr(minStart, ans);
    }
    cout << res << endl;

    return 0;
}