# include <iostream>
# include <string>
# include <vector>
using namespace std;

vector<string> ans;

void codesOfTheString(char *str, char *temp, int i, int j){
    // Base Case
    if (str[i] == '\0'){
        temp[j] = '\0';
        ans.push_back(temp);
        return;
    }

    // Recursive Case
    // For 1 digit letters
    int fdig = str[i] - '0';
    char ch = 'a' + fdig - 1;
    temp[j] = ch;
    codesOfTheString(str, temp, i + 1, j + 1);

    // For 2 digit letters
    if (str[i + 1] != '\0'){
        int sdig = str[i+1] - '0';
        int no = fdig*10 + sdig;
        if (no <= 26 && no >= 1){
            char ch = 'a' + no - 1;
            temp[j] = ch;
            codesOfTheString(str, temp, i + 2, j + 1);
        }
    }
}

int main(){
    char str[100];
    cin >> str;
    char temp[100];
    codesOfTheString(str, temp, 0, 0);
    cout << "[";
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i];
        if (i != ans.size()-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}