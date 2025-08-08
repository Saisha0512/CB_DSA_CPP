# include <iostream>
# include <stack>
# include <queue>
using namespace std;

void enqueue(queue<pair<int, int>> &q, int x, int y){
    pair<int, int> p = make_pair(x, y);
    stack<pair<int, int>> s1, s2;
    bool inserted = false;
    while (!q.empty()){
        pair<int, int> element = q.front();
        q.pop();
        s1.push(element);
    }
    while(!s1.empty()){
        pair<int, int> element = s1.top();
        s1.pop();
        if (element.first == x && inserted == false){
            s2.push(p);
            inserted = true;
        }
        s2.push(element);
    }
    while (!s2.empty()){
        pair<int, int> element = s2.top();
        s2.pop();
        q.push(element);
    }
    if (inserted == false){
        q.push(p);
    }
}

void dequeue(queue<pair<int, int>> &q){
    if (!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        cout << temp.first << " " << temp.second << endl;
    }
}

int main(){
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i ++){
        char ch;
        cin >> ch;
        if (ch == 'E'){
            int x, y;
            cin >> x >> y;
            enqueue(q, x, y);
        }
        else if (ch == 'D'){
            dequeue(q);
        }
    }
    return 0;
}