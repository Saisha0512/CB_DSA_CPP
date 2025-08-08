# include <iostream>
# include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int load = 0;
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
        load += arr[i];
    }
    if (load % n != 0){
        cout << -1 << endl;
        return 0;
    }
    load = load/n;
    int diff = 0, max_load = 0;
    for (int i = 0; i < n; i ++){
        diff += (load - arr[i]);
        max_load = max(max_load, abs(diff));
    }
    cout << max_load << endl;
    return 0;
}