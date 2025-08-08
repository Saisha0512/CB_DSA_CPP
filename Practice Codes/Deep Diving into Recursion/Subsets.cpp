# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
using namespace std;

vector<string> v;

void checkSum(int arr[], int i, int j, int n, int out[], int key, int sum){
    // Base Case
    if (sum == key){
        string ans;
        // Storing in vector to sort later on
        for (int k = 0; k < j; k ++){
            ans += to_string(out[k]) + " ";
        }
        v.push_back(ans);
        return;
    }
    if (i < 0) {
        return;
    }

    // Recursive Case
    sum += arr[i];
    out[j] = arr[i];
    checkSum(arr, i - 1, j + 1, n, out, key, sum);
    sum -= arr[i];
    checkSum(arr, i - 1, j, n, out, key, sum);
}

bool compare(string a, string b){
    return a.length() < b.length();
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int out[100];
    checkSum(arr, n - 1, 0, n, out, key, 0);
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i ++){
        cout << v[i] << endl;
    }
    return 0;
}