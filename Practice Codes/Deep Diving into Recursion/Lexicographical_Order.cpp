# include <iostream>
# include <algorithm>
# include <string>
using namespace std;

void LexiOrder(int n, string ans[], int i, int j, int &cnt){
    // Base Case
    if (i == n + 1){
        return;
    }

    // Recursive Case
    string ch = to_string(i);
    ans[j] = ch;
    cnt ++;
    LexiOrder(n, ans, i + 1, j + 1, cnt);
}

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    string ans[1000];
    LexiOrder(n, ans, 0, 0, cnt);
    sort(ans, ans + cnt);
    for (int i = 0; i < cnt; i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}