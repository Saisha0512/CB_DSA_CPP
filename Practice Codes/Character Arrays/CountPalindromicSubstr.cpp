# include <iostream>
# include <cstring>
using namespace std;

bool isPalindrome(char st[1000]){
    int i = 0;
    int j = strlen(st) - 1;
    while (i <= j){
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
    int n = strlen(st);
    int cnt = 0;
    for (int i = 0; i < n; i ++){
        char temp[1000];
        int k = 0;
        for (int j = i; j < n; j ++){
            temp[k] = st[j];
            temp[k+1] = '\0';
            if (isPalindrome(temp)){
                cnt++;
            }
            k ++;
        }
    }
    cout << cnt << endl;
    return 0;
}