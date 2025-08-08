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

void RevCols(int a[][100], int n) {
  for (int i = 0; i < n; i++) {
    int st = 0;
    int en = n - 1;
    while (st < en) {
      int temp = a[st][i];
      a[st][i] = a[en][i];
      a[en][i] = temp;
      st++;
      en--;
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
  RevCols(arr, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}