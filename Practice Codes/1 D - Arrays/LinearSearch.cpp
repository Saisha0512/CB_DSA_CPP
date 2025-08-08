#include <iostream>
using namespace std;

int LinearSearch(int a[], int n, int x){
    bool ans = false;
    int index = -1;
    for (int j = 0; j < n; j ++){
        if (a[j] == x){
            ans = true;
            index = j;
        }
    }
    return index;
}

int main(){
    int n;
    cin >> n;
    if(n > 0){
        int a[n];
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }
        int m; 
        cin >> m;
        cout << LinearSearch(a, n, m) << endl;
    }
    return 0;
}