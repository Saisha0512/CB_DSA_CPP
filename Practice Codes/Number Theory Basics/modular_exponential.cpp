# include <iostream>
# include <cmath>
using namespace std;

int powerMod(int a, int b, int c){
    long long res = 1;
    long long base = a % c;
    while (b > 0){
        if (b % 2 == 1){
            res = (res * base) % c;
        }
        base = (base * base) % c;
        b /= 2;
    }
    return res;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << powerMod(a, b, c) << endl;
    return 0;
}