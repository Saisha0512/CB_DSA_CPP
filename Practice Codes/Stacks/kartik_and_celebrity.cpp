# include <iostream>
# include <vector>
# include <stack> 
using namespace std;

bool knows(vector<vector<int>> matrix, int a, int b){
    return matrix[a][b] == 1;
}

int findCelebrity(vector<vector<int>> matrix, int n){
    stack<int> s;
    // Pushing everyone in the stack : 
    for (int i = 0; i < n; i ++){
        s.push(i);
    }
    // Eleminating non - celebrities : 
    while (s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(matrix, a, b)){
            s.push(b);
        }
        else {
            s.push(a);
        }
    }
    // Verifying the celebrity : 
    int x = s.top();
    for (int i = 0; i < n; i ++){
        if (matrix[x][i] != 0){
            return -1;
        }
    }

    return x;
}

int main(){
    int n; 
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> matrix[i][j];
        }
    }
    if (findCelebrity(matrix, n) == -1){
        cout << "No Celebrity" << endl;
    }
    else {
        cout << findCelebrity(matrix, n) << endl;
    }

    return 0;
}