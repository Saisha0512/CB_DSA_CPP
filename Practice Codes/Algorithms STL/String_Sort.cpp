# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

bool isPrefix(string a, string b){
    if (a.length() < b.length()){
        if (b. find(a) == 0){
            return true;
        }
    }
    else if (a.length() > b.length()){
        if (a. find(b) == 0){
            return true;
        }
    }
    return false;
}

bool compare(string a, string b){
    if (isPrefix(a, b) == true){
        return a.length() > b.length();
    }
    return a < b;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string arr[n];
    for (int i = 0; i < n; i ++){
        getline(cin, arr[i]);
    }
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i ++){
        cout << arr[i] << endl;
    }
    return 0;
}