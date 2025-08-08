# include <iostream>
# include <algorithm>
# include <string>
using namespace std;

void Subsequences(string s[], char ip[], char op[], int i, int j, int &cnt){
    // Base Case
    if (ip[i] == '\0'){
        op[j] = '\0';
        s[cnt] = op;
        cnt ++;
        return;
    }

    // Recursive Case
    Subsequences(s, ip, op, i+1, j, cnt);
    op[j] = ip[i];
    Subsequences(s, ip, op, i+1, j+1, cnt);
}

int main(){
    char ip[100];
    char op[100];
    string s[100];
    int cnt = 0;
    cin.getline(ip, 100);
    Subsequences(s, ip, op, 0, 0, cnt);
    for (int j = 0; j < cnt; j ++){
        cout << s[j] << ' ';
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}