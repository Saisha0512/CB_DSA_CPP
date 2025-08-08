#include <iostream>
using namespace std;

void DiagonalTraversal(int a[][100], int n, int m) {
  int row = 0, col = 0;
  for (int i = 0; i < (m + n) - 1; i++) {
    if (i % 2 == 0) {
      while (row > 0 && col < m - 1) {
        cout << a[row--][col++] << " ";
      }
      cout << a[row][col] << " ";
      if (col == m - 1) {
        row++;
      } else {
        col++;
      }
    }

    else {
      while (col > 0 && row < n - 1) {
        cout << a[row++][col--] << " ";
      }
      cout << a[row][col] << " ";
      if (row == n - 1) {
        col++;
      } else {
        row++;
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int arr[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  DiagonalTraversal(arr, n, m);

  return 0;
}