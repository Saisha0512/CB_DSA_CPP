# include <iostream>
# include <string>
using namespace std;

void DuplicateChar(char str[], char ans[], int i, int j){
    // Base Case
    if (str[i] == '\0'){
        ans[j] = '\0';
        return;
    }

    // Recursive Case
    if (str[i] == str[i + 1]){
        ans[j] = str[i];
        ans[j+1] = '*';
        DuplicateChar(str, ans, i + 1, j + 2);
    }
    else {
        ans[j] = str[i];
        DuplicateChar(str, ans, i + 1, j + 1); 
    }
}

int main(){
    char str[100];
    cin >> str;
    char ans[100];
    DuplicateChar(str, ans, 0, 0);
    cout << ans << endl;
    return 0;
}