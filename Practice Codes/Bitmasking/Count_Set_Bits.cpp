# include <iostream>
using namespace std;

int SetBits(int n){
    int ans = 0;
    while(n != 0){
        if ((n&1) == 1){
            ans ++;
        }
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        int a;
        cin >> a;
        cout << SetBits(a) << endl;
    }
    return 0;
}