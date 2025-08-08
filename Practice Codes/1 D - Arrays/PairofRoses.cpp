#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void pairofroses(int a[], int n, int x){
    int rose1 = 0, rose2 = 0, min_diff = INT_MAX;
    for(int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j ++){
            int sum = a[i] + a[j];
            if (sum == x){
                int diff = a[j] - a[i];
                if(min_diff > diff){
                    min_diff = diff;
                    rose1 = a[i];
                    rose2 = a[j];
                }
            }
        }
    }
    cout << "Deepak should buy roses whose prices are " << rose1 << " and " << rose2 <<"." << endl;
}

int main(){
    int t;
    cin >> t;
    for(int b = 0; b < t; b ++){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }
        int x; 
        cin >> x;
        sort(a, a + n);
        pairofroses(a, n, x);
    }
    return 0;
}