# include <iostream>
# include <stack>
using namespace std;

int main(){
    int q;
    cin >> q;
    stack<int> modules;
    for (int i = 0; i < q; i ++){
        int qtype;
        cin >> qtype;
        if (qtype == 1){
            if (!modules.empty()){
                cout << modules.top() << endl;
                modules.pop();
            }
            else {
                cout << "No Code" << endl;
            }
        }
        else {
            int price;
            cin >> price;
            modules.push(price);
        }
    }

    return 0;
}