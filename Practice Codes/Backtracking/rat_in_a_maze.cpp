# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void ratInAMaze(vector<vector<int>> maze, int i, int j, int n, string &curr, vector<string> &res, vector<vector<bool>>& visited){
    // Base Case : 
    if (i == n - 1 && j == n - 1){
        res.push_back(curr);
        return;
    }

    // Recursive Case : 
    visited[i][j] = true;
    // Move Down
    if (i + 1 < n && maze[i + 1][j] == 1 && visited[i + 1][j] == false) {
        curr.push_back('D');
        ratInAMaze(maze, i + 1, j, n, curr, res, visited);
        curr.pop_back();
    }

    // Move Up
    if (i - 1 >= 0 && maze[i - 1][j] == 1 && visited[i - 1][j] == false){
        curr.push_back('U');
        ratInAMaze(maze, i - 1, j, n, curr, res, visited);
        curr.pop_back();
    }

    // Move Left
    if (j - 1 >= 0 && maze[i][j - 1] == 1 && visited[i][j - 1] == false){
        curr.push_back('L');
        ratInAMaze(maze, i, j - 1, n, curr, res, visited);
        curr.pop_back();
    }

    // Move Right
    if (j + 1 < n && maze[i][j + 1] == 1 && visited[i][j + 1] == false) {
        curr.push_back('R');
        ratInAMaze(maze, i, j + 1, n, curr, res, visited);
        curr.pop_back();
    }
    visited[i][j] = false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> maze[i][j];
        }
    }
    vector<string> res;
    string curr;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if (maze[0][0] == 1){
        ratInAMaze(maze, 0, 0, n, curr, res, visited);
    }
    sort(res.begin(), res.end());
    if (res.empty()) {
        cout << "" << endl;
    } else {
        for (string& path : res) {
            cout << path << " ";
        }
    }
    return 0;
}