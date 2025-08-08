# include <iostream>
# include <stack>
using namespace std;

bool balancedParanthesis(string s){
    stack<int> p;
    for (int i = 0; s[i] != '\0'; i ++){
        // Checking  for () : 
        if (s[i] == '('){
            p.push(s[i]);
        }
        else if (s[i] == ')'){
            if (p.empty() || p.top() != '('){
                return false;
            }
            p.pop();
        }

        // Checking for [] : 
        if (s[i] == '['){
            p.push(s[i]);
        }
        else if (s[i] == ']'){
            if (p.empty() || p.top() != '['){
                return false;
            }
            p.pop();
        }

        // Checking for {} : 
        if (s[i] == '{'){
            p.push(s[i]);
        }
        else if (s[i] == '}'){
            if (p.empty() || p.top() != '{'){
                return false;
            }
            p.pop();
        }
    }

    return p.empty();
}

int main(){
    string s;
    cin >> s;
    if (balancedParanthesis){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}