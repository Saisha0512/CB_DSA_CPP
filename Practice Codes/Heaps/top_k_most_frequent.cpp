# include <iostream>
# include <queue>
# include <unordered_map>
using namespace std;

typedef pair<int, int> node;

class Compare{
public : 
    bool operator()(node a, node b){
        if (a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n, k;
        cin >> n >> k;
        
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i ++){
            int x;
            cin >> x;
            freq[x] ++;

            // Building new heap : 
            priority_queue<node, vector<node>, Compare> pq; //Max - Heap
            for (auto it : freq){
                pq.push({it.first, it.second});
            }

            // Printing top k
            int printed = 0;
            while (!pq.empty() && printed < k){
                node curr = pq.top();
                pq.pop();
                cout << curr.first << " ";
                printed ++;
            }
        }
        cout << endl;
    }
    return 0;
}