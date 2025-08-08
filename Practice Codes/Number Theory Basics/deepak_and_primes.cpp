#include <iostream>
#include <vector>
using namespace std;

void primeSieve(vector<int> &arr) {
    // Mark all numbers as prime initially : 
    for (int i = 3; i < 500001; i += 2) {
        arr[i] = 1;
    }

    // Sieve :
    for (int i = 3; i * i < 500001; i += 2) {
        if (arr[i] == 1) {
            for (int j = i * i; j < 500001; j += i) {
                arr[j] = 0;
            }
        }
    }

    // Special Cases : 
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}

int main() {
    int n; 
    cin >> n;
    vector<int> arr(500001, 0);
    primeSieve(arr);
    int i = 0, cnt = 0;
    while (cnt < n) {
        if (arr[i] == 1) {
            cnt++;
        }
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}
