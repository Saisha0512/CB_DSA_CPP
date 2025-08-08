# include <iostream>
# include <stack>
using namespace std;

void stockSpan(int price[], int n, int span[]){
    stack<int> idx;
    idx.push(0);
    span[0] = 1;
    for (int i = 1; i < n; i ++){
        int currPrice = price[i];
        while(!idx.empty() && price[idx.top()] <= currPrice){
            idx.pop();
        }

        if (!idx.empty()){
            span[i] = i - idx.top();
        }
        else {
            span[i] = i + 1;
        }
        idx.push(i);
    }
}

int main(){
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i ++){
        cin >> price[i];
    }
    int span[n];
    stockSpan(price, n, span);
    for (int i = 0; i < n; i ++){
        cout << span[i] << " ";
    }
    cout << "END" << endl;

    return 0;
}