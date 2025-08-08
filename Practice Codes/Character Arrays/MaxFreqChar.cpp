# include <iostream>
# include <cstring>
using namespace std;

char MaxFreq(char str[1000]){
    int n = strlen(str);
    int freq[26] = {0};
    for (int i = 0; i < n; i ++){
        freq[str[i] - 'a'] ++;
    }
    int maxidx = 0;
    for (int i = 1; i < 26; i ++){
        maxidx = freq[i] > freq[maxidx] ? i : maxidx;
    }
    char x = 'a' + maxidx;
    return x;
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    cout << MaxFreq(str) << endl;
    return 0;
}