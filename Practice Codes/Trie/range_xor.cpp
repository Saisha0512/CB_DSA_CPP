# include <iostream>
# include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i ++){
        int q;
        cin >> q;
        if (q == 0){
            int el;
            cin >> el;
            arr.push_back(el);
        }
        else if (q == 1){
            int x, l, r;
            cin >> l >> r >> x;
            l --; r --;
            int y = arr[l];
            int max_xor = x ^ arr[l];
            for (int j = l + 1; j <= r; j ++){
                int curr_xor = x^arr[j];
                if (curr_xor > max_xor){
                    max_xor = curr_xor;
                    y = arr[j];
                }
            }
            cout << y << endl;
        }
    }
    return 0;
}