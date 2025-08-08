# include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int ans = 0;
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
        ans ^= arr[i];
    }
    int res = ans;
    int pos = 0;
    while (ans > 0){
        if ((ans&1) == 1){
            break;
        }
        pos ++;
        ans = ans >> 1;
    }

    int x = 1<<pos;
    int num1 = 0;
    for (int i = 0; i < n; i ++){
        if ((arr[i]&x) == 0){
            num1 ^= arr[i];
        }
    }
    int num2 = res^num1;
    if (num1 < num2){
        cout << num1 << " " << num2 << endl;
    }
    else {
        cout << num2 << " " << num1 << endl;
    }
    return 0;
}