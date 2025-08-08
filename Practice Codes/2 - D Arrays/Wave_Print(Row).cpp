#include <iostream>
using namespace std;

void wavePrint(int a[][100], int n, int m) {
  for (int row = 0; row < n; row++) {
    if (row % 2 == 0) {
      for (int col = 0; col < m; col++) {
        cout << a[row][col] << ", ";
      }
    } 
    else {
      for (int col = m - 1; col >= 0; col--) {
        cout << a[row][col] << ", ";
      }
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
  wavePrint(arr, n, m);

  return 0;
}