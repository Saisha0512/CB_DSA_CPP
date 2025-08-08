# include <iostream>
using namespace std;

int NthTriangle(int n, int i){
    if (i == n + 1){
        return 0;
    }

    return i + NthTriangle(n, i + 1);
}

int main(){
    int n;
    cin >> n;
    int i = 1;
    cout << NthTriangle(n, 1) << endl;
    return 0;
}