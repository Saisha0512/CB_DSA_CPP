#include <iostream>
using namespace std;

void MatrixSearch(int a[][100], int n, int m, int el) {
  int row = 0, col = m - 1;
  bool ans = false;
  while (row < n && col >= 0) {
    if (a[row][col] == el) {
      cout << 1 << endl;
      ans = true;
      break;
    } else if (a[row][col] < el) {
      row++;
    } else {
      col--;
    }
  }
  if (ans == false) {
    cout << 0;
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
  int el;
  cin >> el;
  MatrixSearch(arr, n, m, el);

  return 0;
}
