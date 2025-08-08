# include <iostream>
using namespace std;

void RecursivePattern(int n, int i){
    if (i == n){
        return;
    }
    for (int j = 0; j < i + 1; j ++){
        cout << "* ";
    }
    cout << endl;
    RecursivePattern(n, i + 1);
}

int main(){
    int n;
    cin >> n;
    RecursivePattern(n, 0);
    return 0;
}