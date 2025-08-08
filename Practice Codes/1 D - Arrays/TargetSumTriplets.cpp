#include <iostream>
#include <algorithm>
using namespace std;

void targetsumtriplets(int a[], int n, int t){
    for (int i = 0; i < n; i ++){
        int first = a[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k){
            int second = a[j];
            int third = a[k];
            int sum = first + second + third;
            if (sum == t){
                cout << first << ", " << second << " and " << third << endl;
                j ++;
                k --;
            }
            else if (sum > t){
                k --;
            }
            else if (sum < t){
                j ++;
            }
        }
    }
}

int main(){
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int t;
    cin >> t;
    sort(a, a + n);
    targetsumtriplets(a, n, t);
    return 0;
}