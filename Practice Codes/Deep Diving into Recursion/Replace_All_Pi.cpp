# include <iostream>
# include <string>
using namespace std;

void replaceAllPi(string &str, string &temp, int i){
    // Base Case :
    if (i == str.length()){
        return;
    }

    // Recursive Case : 
    if (str[i] == 'p' && str[i + 1] == 'i'){
        temp += "3.14";
        replaceAllPi(str, temp, i + 2);
    }
    else{
        temp += str[i];
        replaceAllPi(str, temp, i + 1);
    }
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    for (int a = 0; a < t; a ++){
        string str;
        getline(cin, str);
        string temp = "";
        replaceAllPi(str, temp, 0);
        cout << temp << endl;
    }
    return 0;
}