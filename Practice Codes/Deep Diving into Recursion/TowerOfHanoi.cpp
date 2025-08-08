# include <iostream>
# include <string>
using namespace std;

void TowerOfHanoi(int n, string src, string dest, string help, int &cnt){
    // Base Case
    if (n == 0){
        return;
    }

    // Recursive Case
    TowerOfHanoi(n - 1, src, help, dest, cnt);
    cout << "Move " << n << "th disc from " << src << " to " << dest << endl;
    cnt ++;
    TowerOfHanoi(n - 1, help, dest, src, cnt);
}

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    TowerOfHanoi(n, "T1", "T2", "T3", cnt);
    cout << cnt << endl;
    return 0;
}