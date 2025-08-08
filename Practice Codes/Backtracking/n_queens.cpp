# include <iostream>
# include <vector>
using namespace std;

bool isSafeToPut(vector<vector<int>> board, int i, int j, int n){
    // Rows & Columns : 
    for (int k = 0; k < n; k ++){
        if (board[i][k] == 1 || board[k][j] == 1){
            return false;
        }
    }

    // Diagonals : 
    int k = i, l = j;
    // Upper - Right : 
    while (i >= 0 && j < n){
        if (board[i][j] == 1){
            return false;
        }
        i --;
        j ++;
    }
    // Upper - Left : 
    while (k >= 0 && l >= 0){
        if (board[k][l] == 1){
            return false;
        }
        k --;
        l --;
    }
    return true;
}

void NQueens(int n, int i, vector<vector<int>> &board, vector<pair<int, int>> &curr, vector<vector<pair<int, int>>> &res){
    // Base Case : 
    if (i == n){
        res.push_back(curr);
        return;
    }

    // Recursive Case : 
    for (int j = 0; j < n; j ++){
        if (isSafeToPut(board, i, j, n)){
            board[i][j] = 1;
            curr.push_back({i + 1, j + 1});
            NQueens(n, i + 1, board, curr, res);
            board[i][j] = 0;
            curr.pop_back();
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> res;
    vector<pair<int, int>> curr;
    NQueens(n, 0, board, curr, res);
    for (auto &line : res){
        for (auto &x : line){
            cout << "{" << x.first << "-" << x.second << "} ";
        }
        cout << " ";
    }
    cout << endl << res.size() << endl;
    return 0;
}