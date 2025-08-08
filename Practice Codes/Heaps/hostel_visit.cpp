# include <iostream>
# include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    priority_queue<long long> pq; //Max - Heap
    for (int i = 0; i < n; i ++){
        int q;
        cin >> q;
        if (q == 1){
            long long x, y;
            cin >> x >> y;
            pq.push(x*x + y*y);
        }
        else if (q == 2){
            while (pq.size() != k){
				pq.pop();
			}
			cout << pq.top() << endl;
        }
    }
    return 0;
}