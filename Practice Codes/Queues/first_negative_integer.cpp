# include <iostream>
# include <deque>
# include <vector>
using namespace std;

int firstNegativeInteger(vector<int> arr){
    for (int i = 0; i < arr.size(); i ++){
        if (arr[i] < 0){
            return arr[i];
        }
    }
    return 0;
}

void firstNegativeIntegerInWindowK(deque<int> &dq, int n, int k){
    while (dq.size() >= k){
        vector<int> arr;
        for (int i = 0; i < k; i ++){
            int element = dq.front();
            dq.pop_front();
            arr.push_back(element);
        }
        cout << firstNegativeInteger(arr) << " ";
        for (int i = arr.size() - 1; i >= 1; i --){
            int element = arr[i];
            dq.push_front(element);
        }
    }
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n, k;
        cin >> n >> k;
        deque<int> dq;
        for (int i = 0; i < n; i ++){
            int x;
            cin >> x;
            dq.push_back(x);
        }

        firstNegativeIntegerInWindowK(dq, n, k);
        cout << endl;
    }

    return 0;
}