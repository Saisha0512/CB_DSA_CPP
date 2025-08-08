# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int x; 
    cin >> x;
    int y;
    cin >> y;
    int cnt = 0;
    for (int i = 0; i < n; i ++){
        if (m >= x){
            m -= x;
            cnt ++;
        }
        else {
            m += y;
        }
    }
    cout << cnt << endl;
    return 0;
}