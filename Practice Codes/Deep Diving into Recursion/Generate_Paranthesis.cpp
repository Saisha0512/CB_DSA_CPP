# include <iostream>
using namespace std;

void generateParanthesis(char arr[], int n, int i, int o, int c){
    // Base Case :
    if (i == 2*n){
        arr[i] = '\0';
        cout << arr << endl;
        return;
    }

    // Recursive Case :
    if (c < o){
        arr[i] = ')';
        generateParanthesis(arr, n, i + 1, o, c + 1);
    }
    if (o < n){
        arr[i] = '(';
        generateParanthesis(arr, n, i + 1, o + 1, c);
    }
}

int main(){
    int n;
    cin >> n;
    char arr[2*n];
    generateParanthesis(arr, n, 0, 0, 0);
    return 0;
}