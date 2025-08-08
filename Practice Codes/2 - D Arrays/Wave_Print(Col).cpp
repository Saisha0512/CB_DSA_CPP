#include <iostream>
using namespace std;

void printWave(int a[][100], int n, int m){
    for (int col = 0; col < m; col ++){
        if (col % 2 == 0){
            for (int row = 0; row < n; row ++){
                cout << a[row][col] << ", ";
            }
        }
        else {
            for (int row = n - 1; row >= 0; row --){
                cout << a[row][col] << ", ";
            }
        }
    }
    cout << "END";
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> arr[i][j];
        }
    }
    printWave(arr, n, m);

    return 0;
}