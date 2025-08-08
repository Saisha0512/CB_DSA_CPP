# include <iostream>
# include <cstring>
using namespace std;

int countMaxWindowSize(char str[], char ch, int k){
    int n = strlen(str);
    int i = 0;
    int j = 0;
    int ans = 0;
    int swap = 0;
    for (j; j < n; j ++){
        if (str[j] != ch){
            swap ++;
        }
        if (swap == k){
            break;
        }
    }
    while (i < j){
        if (str[j + 1] == ch && j < n){
            j ++;
        }
        int currlen = j - i + 1;
        ans = max(ans, currlen);
        i ++;
        if (j < n && str[i - 1] != ch){
            j ++;
        }
    }
    return ans;
}

int main(){
    int k;
    cin >> k;
    cin.ignore();
    char str[1000];
    cin.getline(str, 1000);
    if (k >= strlen(str)){
        cout << strlen(str) << endl;
        return 0;
    }
    int ansA = countMaxWindowSize(str, 'a', k);
    int ansB = countMaxWindowSize(str, 'b', k);
    cout << max(ansA, ansB) << endl;
    return 0;
}