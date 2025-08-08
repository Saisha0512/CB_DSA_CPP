# include <iostream>
# include <cstring>
# include <cstdlib>
using namespace std;

bool isCBNumber(long long num){
    int cbNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    if (num == 0 || num == 1){
        return false;
    }
    for (int i = 0; i < 10; i ++){
        int cb = cbNumbers[i];
        if (num == cb){
            return true;
        }
        if (num % cb == 0){
            return false;
        }
    }
    return true;
}

bool isUsed(bool visited[], int start, int end){
    for (int i = start; i <= end; i ++){
        if (visited[i]){
            return true;
        }
    }
    return false;
}

int countCBNumbers(char str[], int n){
    bool visited[17] = {false};
    int cnt = 0;
    for (int len = 1; len <= n; len ++){
        for (int i = 0; i <= n - len; i ++){
            int st = i;
            int end = i + len - 1;
            char temp[17];
            strncpy(temp, str + st, len);
            temp[len] = '\0';
            long long num = std::atoi(temp);

            if (isCBNumber(num) && !isUsed(visited, st, end)){
                cnt ++;
                for (int k = st; k <= end; k ++){
                    visited[k] = true;
                }
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    char str[18];
    cin.getline(str, 17);
    cout << countCBNumbers(str, n) << endl;

    return 0;
}