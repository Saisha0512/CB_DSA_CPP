#include <iostream>
using namespace std;

void SpiralPrint(int a[][100], int n, int m) {
  int strow = 0, stcol = 0, enrow = n - 1, encol = m - 1;
  while (strow <= enrow && stcol <= encol) {
    for (int row = strow; row <= enrow; row++) {
      cout << a[row][stcol] << ", ";
    }
    stcol++;

    for (int col = stcol; col <= encol; col++) {
      cout << a[enrow][col] << ", ";
    }
    enrow--;

    if (stcol <= encol) {
      for (int row = enrow; row >= strow; row--) {
        cout << a[row][encol] << ", ";
      }
      encol--;
    }

    if (strow <= enrow) {
      for (int col = encol; col >= stcol; col--) {
        cout << a[strow][col] << ", ";
      }
      strow++;
    }
  }
  cout << "END";
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
  SpiralPrint(arr, n, m);

  return 0;
}