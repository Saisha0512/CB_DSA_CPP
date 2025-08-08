# include <iostream>
using namespace std;

int SetBits(int n){
    int cnt = 0;
    while (n > 0){
        int bit = (n&1);
        if (bit == 1){
            cnt ++;
        }
        n = n>>1;
    }
    return cnt;
}

int SetBitsBTW(int a, int b){
    int cnt = 0;
    for (int i = a; i <= b; i ++){
        cnt += SetBits(i);
    }
    return cnt;
}

int main(){
    int q;
    cin >> q;
    for (int i = 0; i < q; i ++){
        int a, b;
        cin >> a >> b;
        cout << SetBitsBTW(a, b) << endl;
    }
    return 0;
}