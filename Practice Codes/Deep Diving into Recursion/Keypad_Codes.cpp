# include <iostream>
using namespace std;

string keys[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};

void keypadCodes(char str[], char temp[], int i, int j, int &cnt){
    // Base Case :
    if (str[i] == '\0'){
        temp[j] = '\0';
        cout << temp << " ";
        cnt ++;
        return;
    }

    // Recursive Case :
    int no = str[i] - '0';
    for (int k = 0; keys[no][k] != '\0'; k ++){
        temp[j] = keys[no][k];
        keypadCodes(str, temp, i + 1, j + 1, cnt);
    }
}

int main(){
    char str[100];
    char temp[100];
    cin >> str;
    int cnt = 0;
    keypadCodes(str, temp, 0, 0, cnt);
    cout << endl;
    cout << cnt << endl;
    return 0;
}