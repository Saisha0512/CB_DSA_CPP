# include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int maxans = 0;
    for (int i = a; i <= b; i ++){
        for (int j = i; j <= b; j ++){
            int ans = i^j;
            if (ans >= maxans){
                maxans = ans;
            }
        }
    }
    cout << maxans << endl;
    return 0;
}