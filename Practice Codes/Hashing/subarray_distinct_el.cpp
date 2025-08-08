# include <iostream>
# include <unordered_map>
# include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    int left = 0, sum = 0;
    for (int right = 0; right < arr.size(); right ++){
        freq[arr[right]] ++;

        while (freq[arr[right]] > 1){
            freq[arr[left]] --;
            left ++;
        }

        for (int i = left; i <= right; i ++){
            sum += (i - left + 1);
        }
    }
    cout << sum << endl;
    return 0;
}