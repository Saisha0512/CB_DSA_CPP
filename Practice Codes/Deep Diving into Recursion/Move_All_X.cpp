# include <iostream>
# include <string>
using namespace std;

void moveAllX(string &str, int n, int i, int j){
    // Base Case :
    if (j == n){
        while(i < n){
            str[i] = 'x';
            i ++;
        }
        return;
    }

    // Recursive Case :
    if(str[j] != 'x'){
        str[i] = str[j];
        moveAllX(str, n, i + 1, j + 1);
    }
    else{
        moveAllX(str, n, i, j + 1);
    }
}

int main(){
    string str;
    getline(cin, str);
    int n = str.length();
    moveAllX(str, n, 0, 0);
    cout << str << endl;
    return 0;
}