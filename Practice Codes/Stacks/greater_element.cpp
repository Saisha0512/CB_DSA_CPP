# include <iostream>
# include <vector>
# include <stack>
using namespace std;

void greaterElement(vector<int> &result, vector<int> arr, int n){
    stack<int> s;
    for (int i = 2*n - 1; i >= 0; i --){
        int curr = arr[i % n];
        while (!s.empty() && curr >= s.top()){
            s.pop();
        }

        if (i < n){
            if (!s.empty()){
                result[i] = s.top();
            }
        }
        s.push(curr);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    vector<int> result(n, -1);
    greaterElement(result, arr, n);
    for (int i = 0; i < n; i ++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}