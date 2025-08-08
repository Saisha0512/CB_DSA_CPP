# include <iostream>
# include <cstring>
using namespace std;

void OddEvenChar(char str[]){
    int n = strlen(str);
    for (int i = 0; i < n; i ++){
        if (i % 2 == 0){
            str[i] = str[i] + 1;
        }
        else{
            str[i] = str[i] - 1;
        }
    }
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    OddEvenChar(str);
    cout << str << endl;
    return 0;
}