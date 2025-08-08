# include <iostream>
# include <cstring>
using namespace std;

bool isPalindrome(char st[1000]){
    int n = strlen(st);
    int i = 0;
    int j = n - 1;
    while (i < j){
        if (st[i] != st[j]){
            return false;
        }
        i ++;
        j --;
    }
    return true;
}

int main(){
    char st[1000];
    cin.getline(st, 1000);
    if(isPalindrome(st)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}