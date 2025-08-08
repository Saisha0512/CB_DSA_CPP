#include <iostream>
#include <string>
using namespace std;

void printASCIISubseq(string str, string res, int i, int &cnt){
    if (i == str.size()){
        cout << res << " ";
        cnt ++;
        return;
    }

    // If the ith character is not included in the sub - string.
    printASCIISubseq(str, res, i + 1, cnt);
    // If the ith character is included in the sub - string.
    printASCIISubseq(str, res + str[i], i + 1, cnt);
    // To include the ASCII Code of the ith character in the sub - string,
    printASCIISubseq(str, res + to_string(97 + str[i]-'a'), i + 1, cnt);
}

int main(){
    string str;
    getline(cin, str);
    int cnt = 0;
    string res = "";
    printASCIISubseq(str, res, 0, cnt);
    cout << endl;
    cout << cnt << endl; 
    return 0;
}