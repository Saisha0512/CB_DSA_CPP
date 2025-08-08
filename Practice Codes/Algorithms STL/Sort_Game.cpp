# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

bool compare(pair <string, int> a, pair <string, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

void sortGame(pair <string, int> arr[], pair <string, int> temp[], int n, int cnt){
    sort(arr, arr + n, compare);
    for (int i = 0; i < cnt; i ++){
        temp[i] = arr[i];
    }
}

int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    pair <string, int> arr[n];
    for (int i = 0; i < n; i ++){
        cin>> arr[i].first;
        cin >> arr[i].second;
    }
    int cnt = 0;
    for (int j = 0; j < n; j ++){
        if (arr[j].second >= x){
            cnt ++;
        }
    }
    pair <string, int> temp[cnt];
    sortGame(arr, temp, n, cnt);
    for (int i = 0; i < cnt; i ++){
        cout << temp[i].first << " " << temp[i].second << endl;
    }
    return 0;
}