# include <iostream>
# include <stack>
using namespace std;

int histogram(int height[], int n){
    int area = 0;
    stack<int> idx;
    for (int i = 0; i <= n; i ++){
        int currHeight = (i == n) ? 0 : height[i];
        while (!idx.empty() && height[idx.top()] >= currHeight){
            int ht = height[idx.top()];
            idx.pop();
            int width = idx.empty() ? i : (i - idx.top() - 1);
            area = max(area, ht*width);
        }
        idx.push(i);
    }

    return area;
}

int main(){
    int n;
    cin >> n;
    int height[n];
    for (int i = 0; i < n; i ++){
        cin >> height[i];
    }
    cout << histogram(height, n) << endl;

    return 0;
}