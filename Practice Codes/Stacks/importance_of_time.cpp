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

int importanceOfTime(stack<int> &calling, stack<int> &ideal){
    int time = 0;
    while (!calling.empty()){
        if (calling.top() == ideal.top()){
            time ++;
            calling.pop();
            ideal.pop();
        }
        else {
            int x = calling.top();
            calling.pop();
            insertAtBottom(calling, x);
            time ++;
        }
    }

    return time;
}

int main(){
    int n;
    cin >> n;
    stack<int> calling;
    stack<int> ideal;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        calling.push(x);
    }
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        ideal.push(x);
    }
    recReverse(calling);
    recReverse(ideal);
    cout << importanceOfTime(calling, ideal) << endl;

    return 0;
}