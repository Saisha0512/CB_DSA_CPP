# include <iostream>
# include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    // Base Case : 
    if (s.empty()){
        s.push(x);
        return;
    }

    // Recursive Case : 
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void recReverse(stack<int> &s){
    // Base Case : 
    if (s.empty()){
        return;
    }

    // Recursive Case : 
    int x = s.top();
    s.pop();
    recReverse(s);
    insertAtBottom(s, x);
}

int main(){
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        s.push(x);
    }
    recReverse(s);
    while (!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}