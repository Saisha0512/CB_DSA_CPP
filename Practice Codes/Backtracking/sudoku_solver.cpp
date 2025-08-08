# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

bool canPlace(vector<vector<int>> &sudoku, int i, int j, int n, int num){
    // Checking for Row & Column : 
    for (int k = 0; k < n; k ++){
        if (sudoku[i][k] == num || sudoku[k][j] == num){
            return false;
        }
    }

    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for (int x = sx; x < sx + rn; x ++){
        for (int y = sy; y < sy + rn; y ++){
            if (sudoku[x][y] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &sudoku, int i, int j, int n){
    // Base Case  :
    if (i == n){
        // Print the Sudoku
        for (int x = 0; x < n; x ++){
            for (int y = 0; y < n; y ++){
                cout << sudoku[x][y] << " ";
            }
            cout << endl;
        }

        return true;
    }
    // Row end : 
    if (j == n){
        return sudokuSolver(sudoku, i + 1, 0, n);
    }
    // Skip the pre-filled cells : 
    if (sudoku[i][j] != 0){
        return sudokuSolver(sudoku, i, j + 1, n);
    }

    // Recursive Case : 
    // Fill the current cell with the possible options : 
    for (int num = 1; num <= n; num ++){
        if (canPlace(sudoku, i, j, n, num)){
            sudoku[i][j] = num;

            bool rem = sudokuSolver(sudoku, i, j + 1, n);
            if (rem){
                return true;
            }
        }
    }
    // Backtracking : 
    sudoku[i][j] = 0;
    return false;
}

int main(){
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i ++){
        for (int j = 0; j < 9; j ++){
            cin >> sudoku[i][j];
        }
    }
    sudokuSolver(sudoku, 0, 0, 9);
    return 0;
}