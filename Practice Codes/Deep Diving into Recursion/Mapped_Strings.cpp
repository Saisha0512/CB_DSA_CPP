# include <iostream>
# include <vector>
# include <string>
using namespace std;

vector<string> ans;

void mappedStrings(char str[], char temp[], int i, int j){
    // Base Case :
    if (str[i] == '\0'){
        temp[j] = '\0';
        ans.push_back(temp);
        return;
    }

    // Recursive Case :
    // For 1 digit letters :
    int fdig = str[i] - '0';
    char ch = 'A' + fdig - 1;
    temp[j] = ch;
    mappedStrings(str, temp, i + 1, j + 1);

    // For 2 digit letters :
    if (str[i + 1] != '\0'){
        int sdig = str[i + 1] - '0';
        int no = fdig*10 + sdig;
        if (no >= 10 && no <= 26){
            char ch = 'A' + no - 1;
            temp[j] = ch;
            mappedStrings(str, temp, i + 2, j + 1);
        }
    }
}

int main(){
    char str[100];
    cin.getline(str, 100);
    char temp[100];
    mappedStrings(str, temp, 0, 0);
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i] << endl;
    }
    return 0;
}