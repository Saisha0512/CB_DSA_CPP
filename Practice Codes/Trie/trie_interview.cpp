# include <iostream>
# include <climits>
# include <vector>
using namespace std;

class Node {
public :    
    Node *left; // For 0
    Node *right; // For 1
};

class Trie {
    Node *root = new Node();

public : 
    void insert(int val){
        Node *temp = root;
        for (int i = 31; i >= 0; i --){
            int bit = (val >> i) & 1;
            if (bit == 0){
                if (temp -> left == NULL){
                    temp -> left = new Node();
                }
                temp = temp -> left;
            }
            else if (bit == 1){
                if (temp -> right == NULL){
                    temp -> right = new Node();
                }
                temp = temp -> right;
            }
        }
    }

    int max_xor(int val){
        int curr_ans = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i --){
            int bit = (val >> i) & 1;
            if (bit == 0){
                // Finding complementary of 0 -> 1
                if (temp -> right != NULL){
                    temp = temp -> right;
                    curr_ans += (1 << i);
                }
                else {
                    temp = temp -> left;
                }
            }
            else {
                // Finding complementary of 1 -> 0
                if (temp -> left != NULL){
                    temp = temp -> left;
                    curr_ans += (1 << i);
                }
                else {
                    temp = temp -> right;
                }
            }
        }
        return curr_ans;
    }
};

int maxXorSubarray(vector<int> arr, int s, int e){
    Trie t;
    t.insert(0);
    int max_xor = 0;
    int prefix = 0;
    for (int i = s; i <= e; i ++){
        prefix ^= arr[i];
        max_xor = max(max_xor, t.max_xor(prefix));
        t.insert(prefix);
    }
    return max_xor;
}

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    vector<int> prexor(n);
    prexor[0] = arr[0];
    for (int i = 1; i < n; i ++){
        prexor[i] = prexor[i - 1] ^ arr[i];
    }

    int res = INT_MIN;
    for (int i = 0; i < n - 1; i ++){
        // Left part [0 ... i]
        int leftMax = maxXorSubarray(arr, 0, i);

        // Right part [i + 1 ... n - 1]
        int rightMax = maxXorSubarray(arr, i + 1, n - 1);

        res = max(res, leftMax + rightMax);
    }
    cout << res << endl;
    return 0;
}

