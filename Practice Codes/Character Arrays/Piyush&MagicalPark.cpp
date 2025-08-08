# include <iostream>
# include <cstring>
using namespace std;

int main(){
    int n, m, k, s;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> s;
    char park[n][m];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> park[i][j];
        }
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (s < k){
                cout << "No" << endl;
                return 0;
            }
            if (park[i][j] == '#') {
                break;
            }
            if (park[i][j] == '*') {
                s += 5;
            }
            else if (park[i][j] == '.') {
                s -= 2;
            }
            
            if (j != m - 1){
                s --;
            }
        }
    }
    if (s >= k){
        cout << "Yes" << endl << s << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}