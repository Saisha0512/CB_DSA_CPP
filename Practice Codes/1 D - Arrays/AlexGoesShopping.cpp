#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    if (q < 2*n){
        for (int j = 0; j < q; j ++){
            int amt;
            cin >> amt;
            int k;
            cin >> k;
            int count = 0;
            for (int d = 0; d < n; d ++){
                if(amt % a[d] == 0){
                    count ++;
                }
            }
            if (count >= k){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}