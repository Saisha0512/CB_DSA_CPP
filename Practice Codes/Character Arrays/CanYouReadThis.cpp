# include <iostream>
# include <cstring>
using namespace std;

void CamelCase(char str[]){
    int n = strlen(str);
    for (int i = 0; i < n; i ++){
        cout << str[i];
        if (str[i + 1] >= 'A' && str[i + 1] <= 'Z'){
            cout << endl;
        }
    }
    cout << endl;
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    CamelCase(str);
    return 0;
}