#include <iostream>
using namespace std;

int maxcircularsum(int a[], int n){
    if(n == 1){
        return a[0];
    }
    int tsum = 0;
    for (int i = 0; i < n; i ++){
        tsum += a[i];
    }
    int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
    for (int j = 1; j < n; j ++){
        curr_max = max(curr_max + a[j], a[j]);
        max_so_far = max(max_so_far, curr_max);

        curr_min = min(curr_min + a[j], a[j]);
        min_so_far = min(min_so_far, curr_min);
    }
    if (min_so_far == tsum){
        return max_so_far;
    }
    
    return max(max_so_far, tsum - min_so_far);
}

int main(){
    int t;
    cin >> t;
    for (int b = 0; b < t; b ++){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }
        cout << maxcircularsum(a, n) << endl;
    }
    return 0;
}