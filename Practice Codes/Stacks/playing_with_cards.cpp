# include <iostream>
# include <stack>
using namespace std;

int ithPrimeNumber(int i){
    int prime = 1;
    int primeCount = 0;
    while (i != primeCount){
        bool ans = false;
        prime ++;
        for (int i = 2; i <= prime; i ++){
            if (i != prime){
                if (prime % i == 0){
                    ans = false;
                    break;
                }
            }
            else if (i == prime){
                ans = true;
            }
        }
        if (ans == true){
            primeCount ++;
        }
    }
    return prime;
}

int main(){
    int n, q;
    cin >> n >> q;
    stack<int> a[100]; // Array of Stacks A0, A1, ...
    stack<int> b[100]; // Array of STacks B0, B1, ...
    // Pushing the numbered cards into A0 Stack : 
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        a[0].push(x);
    }
    // Checking ith piles till q : 
    for (int i = 1; i <= q; i ++){
        while(!a[i - 1].empty()){
            int x = a[i - 1].top();
            a[i - 1].pop();
            if (x % ithPrimeNumber(i) == 0){
                b[i].push(x);
            }
            else {
                a[i].push(x);
            }
        }
    }

    // Printing the final stacks : 
    for (int i = 1; i <= q; i ++){
        while(!b[i].empty()){
            cout << b[i].top() << endl;
            b[i].pop();
        }
    }
    while (!a[q].empty()){
        cout << a[q].top() << endl;
        a[q].pop();
    }

    return 0;
}