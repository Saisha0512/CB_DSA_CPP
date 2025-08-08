#include <iostream>
using namespace std;

void Transpose(int a[][100], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j) {
        swap(a[i][j], a[j][i]);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  Transpose(arr, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}