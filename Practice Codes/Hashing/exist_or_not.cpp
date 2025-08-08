# include <iostream>
# include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++){
            int el;
            cin >> el;
            m[el] += 1;
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i ++){
            int el;
            cin >> el;
            if (m.count(el) == 0){
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}