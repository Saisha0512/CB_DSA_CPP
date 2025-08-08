#include <iostream>
using namespace std;

int finalcost(int a[], int rick[], int cab[], int n, int m){
    //For Rickshaws.
    int rick_sum = 0, rick_tsum = 0;
    for (int b = 0; b < n; b ++){
        rick_sum += min(rick[b]*a[0], a[1]);
    }
    rick_tsum = min(rick_sum, a[2]);
    //For Cabs.
    int cab_sum = 0, cab_tsum = 0;
    for (int c = 0; c < m; c ++){
        cab_sum += min(cab[c]*a[0], a[1]);
    }
    cab_tsum = min(cab_sum, a[2]);

    int final_cost = 0;
    final_cost = min(rick_tsum + cab_tsum, a[3]);

    return final_cost;
}

int main(){
    int t; 
    cin >> t;
    for (int i = 0; i < t; i ++){
        int a[4]; 
        for (int j = 0; j < 4; j ++){
            cin >> a[j];
        }
        int n;
        cin >> n;
        int m;
        cin >> m;
        int rick[n];
        int cab[m];
        for (int k = 0; k < n; k ++){
            cin >> rick[k];
        }
        for (int l = 0; l < m; l ++){
            cin >> cab[l];
        }
        cout << finalcost(a, rick, cab, n, m) << endl;
    }
    return 0;
}