# include <iostream>
# include <string>
# include <vector>
using namespace std;

void classAssignment(char temp[], int n, int i, int &cnt){
    // Base Case : 
    if (i == n){
        temp[n] = '\0';
        cnt ++;
        return;
    }

    // Recursive Case :
    if(temp[i - 1] == 'b' && i > 0){
        temp[i] = 'a';
        classAssignment(temp, n, i + 1, cnt);
    }
    else{
        temp[i] = 'b';
        classAssignment(temp, n, i + 1, cnt);
        temp[i] = 'a';
        classAssignment(temp, n, i + 1, cnt);
    }
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n;
        cin >> n;
        int cnt = 0;
        char temp[n+1];
        classAssignment(temp, n, 0, cnt);
        cout << '#' << a+1 << " : " << cnt << endl;
    }
    return 0;
}