#include <iostream>
using namespace std;

int min_swap(int a[], int n) {
  int swap = 0;
  for (int i = 0; i < n - 2; i++) {
    int min_el = a[i];
    int min_ind = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < min_el) {
        min_el = a[j];
        min_ind = j;
      }
    }
    if (a[i] != min_el) {
      int temp = a[i];
      a[i] = min_el;
      a[min_ind] = temp;
      swap += 1;
    }
  }
  return swap;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << min_swap(arr, n) << endl;
  return 0;
}