# include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int cnt[64] = {0};
    for (int i = 0; i < n; i ++){
        int pos = 0;
        int no = arr[i];
        while (no > 0){
            if ((no&1) == 1){
                cnt[pos] ++;
            }
            pos ++;
            no >>= 1;
        }
    }
    int ans = 0;
    int k = 0;
    for (int i = 0; i < 64; i ++){
        cnt[i] %= 3;
        ans = (ans|cnt[i]<<k);
        k ++;
    }
    cout << ans << endl;
    return 0;
}