# include <iostream>
# include <cstring>
using namespace std;

int main(){
    char str[1000];
    cin.getline(str, 1000);
    int n = strlen(str);
    int i = 0;
    int j = 1;
    cout << str[i];
    for (int k = 0; k < n-1; k ++){
        int x = str[j] - str[i];
        cout << x;
        cout << str[j];
        i = j;
        j = i + 1;
    }
    return 0;
}