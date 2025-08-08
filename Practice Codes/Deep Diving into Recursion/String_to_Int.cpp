# include <iostream>
# include <string>
using namespace std;

void stringToInt(string str, int &num, int i){
    // Base Case :
    if (i == str.length()){
        return;
    }

    // Recursive Case :
    int dig = str[i] - '0';
    num = num*10 + dig;
    stringToInt(str, num, i + 1);
}

int main(){
    string str;
    getline(cin, str);
    int num = 0;
    stringToInt(str, num, 0);
    cout << num << endl;
    return 0;
}