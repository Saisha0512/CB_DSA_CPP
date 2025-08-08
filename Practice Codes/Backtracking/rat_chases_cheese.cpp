# include <iostream>
# include <vector>
using namespace std;

bool ratChasesCheese(vector<vector<char>> maze, int n, int m, int i, int j, vector<vector<int>> &sol){
    // Base Case : 
    if (maze[i][j] == 'X' || sol[i][j] == 1) {
        return false;
    }

    if (i == n - 1 && j == m - 1){
        sol[i][j] = 1;
        return true;
    }

    // Recursive Case : 
    sol[i][j] = 1;
    // Move Up : 
    if (i - 1 >= 0 && maze[i - 1][j] == 'O'){
        bool ans = ratChasesCheese(maze, n, m, i - 1, j, sol);
        if (ans){
            return true;
        }
    }

    // Move Down : 
    if (i + 1 < n && maze[i + 1][j] == 'O'){
        bool ans = ratChasesCheese(maze, n, m, i + 1, j, sol);
        if (ans){
            return true;
        }
    }

    // Move Left : 
    if (j - 1 >= 0 && maze[i][j - 1] == 'O'){
        bool ans = ratChasesCheese(maze, n, m, i, j - 1, sol);
        if (ans){
            return true;
        }
    }

    // Move Right : 
    if (j + 1 < m && maze[i][j + 1] == 'O'){
        bool ans = ratChasesCheese(maze, n, m, i, j + 1, sol);
        if (ans){
            return true;
        }
    }

    sol[i][j] = 0;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<int>> sol(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> maze[i][j];
        }
    }
    if (ratChasesCheese(maze, n, m, 0, 0, sol)){
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NO PATH FOUND" << endl;
    }
    return 0;
}