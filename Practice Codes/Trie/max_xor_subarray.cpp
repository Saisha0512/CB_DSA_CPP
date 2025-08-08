# include <iostream>
# include <vector>
using namespace std;

class Node {
public : 
    Node *left;     // For 0
    Node *right;    // For 1
};

class Trie {
    Node *root = new Node ();
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
            else {
                if (temp -> right == NULL){
                    temp -> right = new Node();
                }
                temp = temp -> right;
            }
        }
    }

    int max_xor_helper(int val){
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

    int max_xor(vector<int> input){
        int max_xor = 0;
        int prefix_xor = 0;
        insert(0);
        for (int i = 0; i < input.size(); i ++){
            prefix_xor ^= input[i];
            int curr_xor = max_xor_helper(prefix_xor);
            max_xor = max(max_xor, curr_xor);
            insert(prefix_xor);
        }
        return max_xor;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i ++){
        cin >> in[i];
    }
    Trie t;
    cout << t.max_xor(in) << endl;
    return 0;
}