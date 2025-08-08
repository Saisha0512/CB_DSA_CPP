# include <iostream>
# include <climits>
# include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i ++){
        int el;
        cin >> el;
        freq[el] ++;
    }

    int maxFreq = INT_MIN;
    int maxNum = INT_MAX;
    for (auto p : freq){
        if (p.second > maxFreq || (p.second == maxFreq && p.first < maxNum)){
            maxFreq = p.second;
            maxNum = p.first;
        }
    }
    cout << maxNum << endl;
    return 0;
}