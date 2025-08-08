# include <iostream>
# include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq; //Max - Heap
    for (int i = 0; i < n; i ++){
        int element;
        cin >> element;
        pq.push(element);
    }
    for (int i = 0; i < k - 1; i ++){
        pq.pop();
    }
    cout << pq.top() << endl;
    return 0;
}