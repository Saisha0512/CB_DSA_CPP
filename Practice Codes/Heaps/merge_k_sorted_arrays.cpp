# include <iostream>
# include <vector>
# include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> arr){
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // Min - Heap
    // Pushing all the 0th elements in the heap : 
    for (int i = 0; i < arr.size(); i ++){
        pq.push({arr[i][0], {i, 0}});
    }

    while (!pq.empty()){
        node curr = pq.top();
        pq.pop();
        result.push_back(curr.first);
        int x = curr.second.first;
        int y = curr.second.second;

        if (y + 1 < arr[x].size()){
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> arr[i][j];
        }
    }
    vector<int> res = mergeKSortedArrays(arr);
    for (auto x : res){
        cout << x << " ";
    }
    return 0;
}