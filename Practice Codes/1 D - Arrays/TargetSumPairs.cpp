#include <algorithm>
#include <iostream>
using namespace std;

int compare(int a, int b) {
  return a < b;
}

void targetsumpair(int a[], int n, int x) {
  int left = 0;
  int right = n - 1;
  while (left < right) {
    int sum = a[left] + a[right];
    if (sum == x) {
      cout << a[left] << " and " << a[right] << endl;
      left++;
      right--;
    } else if (sum > x) {
      right--;
    } else if (sum < x) {
      left++;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  sort(a, a + n, compare);
  targetsumpair(a, n, x);
  return 0;
}