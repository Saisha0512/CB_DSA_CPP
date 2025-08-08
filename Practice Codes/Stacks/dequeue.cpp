# include <iostream>
# include <stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2){
    while (!s1.empty()){
        int x = s1.top();
        s1.pop();
        s2.push(x);
    }
}

int main(){
    int n;
    cin >> n;
    stack<int> s1;
    stack<int> s2;
    for (int i = 0; i < n; i ++){
        s1.push(i);
    }
    for (int i = 0; i < n; i ++){
        transfer(s1, s2);
        cout << s2.top() << " ";
        s2.pop();
        transfer(s2, s1);
    }

    return 0;
}