# include <iostream>
# include <cstring>
using namespace std;

void ToggleCase(char str[]){
    int n = strlen(str);
    for (int i = 0; i < n; i ++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        else {
            str[i] = str[i] - 32;
        }
    }
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    ToggleCase(str);
    cout << str << endl;
    return 0;
}