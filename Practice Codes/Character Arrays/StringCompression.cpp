# include <iostream>
# include <cstring>
using namespace std;

void StringCompression (char str[]){
    int cnt = 0;
    int i = 0;
    for (int j = 0; str[j] != '\0'; j ++){
        cnt ++;
        if (str[j] != str[i]){
            cnt --;
            if (cnt == 1){
                cout << str[i];
                i = j;
                cnt = 1;
            }
            else if (cnt > 1){
                cout << str[i] << cnt;
                i = j;
                cnt = 1;
            }
        } 
    }
    if (cnt == 1){
        cout << str[i] << endl;
    }
    else if (cnt > 1){
        cout << str[i] << cnt << endl;
    }
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    StringCompression(str);
    return 0;
}