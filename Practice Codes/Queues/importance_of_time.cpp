# include <iostream>
# include <queue>
using namespace std;

int importanceOfTime(queue<int> calling, queue<int> ideal, int n){
    int time = 0;
    while (!calling.empty()){
        while (calling.front() != ideal.front()){
            int element = calling.front();
            calling.pop();
            calling.push(element);
            time ++;
        }
        calling.pop();
        ideal.pop();
        time ++;
    }

    return time;
}

int main(){
    int n;
    cin >> n;
    queue<int> calling;
    queue<int> ideal;

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
    cout << importanceOfTime(calling, ideal, n) << endl;

    return 0;
}
