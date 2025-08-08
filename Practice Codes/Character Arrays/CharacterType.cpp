# include <iostream>
# include <cstring>
using namespace std;

int main(){
    char str[1000];
    cin.getline(str, 1000);
    for (int i = 0; i < strlen(str); i ++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            cout << "U" << endl;
        }
        else if (str[i] >= 'a' && str[i] <= 'z'){
            cout << "L" << endl;
        }
        else {
            cout << "I" << endl;
        }
    }
    return 0;
}