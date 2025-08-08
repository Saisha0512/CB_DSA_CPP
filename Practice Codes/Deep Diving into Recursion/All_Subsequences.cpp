# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

bool compare(string a, string b){
    return a.compare(b) < 0;
}

void AllSubsequences(string s[], char ip[], char op[], int i, int j, int &cnt){
    // Base Case
    if (ip[i] == '\0'){
        op[j] = '\0';
        s[cnt] = op;
        cnt ++;
        return;
    }

    // Recursive Case
    AllSubsequences(s, ip, op, i+1, j, cnt);
    op[j] = ip[i];
    AllSubsequences(s, ip, op, i+1, j+1, cnt);
}

int main(){
    int a;
    cin >> a;
    cin.ignore();
    for (int i = 0; i < a; i ++){
        char ip[20];
        char op[100];
        string s[100];
        int n = 0;
        cin >> ip;
        AllSubsequences(s, ip, op, 0, 0, n);
        sort(s, s+n);
        for (int j = 0; j < n; j ++){
            cout << s[j] << endl;
        }
    }
    return 0;
}