# include <iostream>
# include <cstring>
using namespace std;

void RemoveDuplicates(char str[]){
    int cnt = 0;
    int i = 0; 
    for (int j = 0; str[j] != '\0'; j ++){
        if (str[j] != str[i]){
            i ++;
            str[i] = str[j];
        }
    }
    i++;
    str[i] = '\0';
}

int main(){
    char str[1000];
    cin.getline(str, 1000);
    RemoveDuplicates(str);
    cout << str << endl;
    return 0;
}