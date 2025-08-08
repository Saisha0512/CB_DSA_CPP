#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    Node *left = nullptr;
    Node *right = nullptr;
};

class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int val) {
        Node *temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (bit == 0) {
                if (!temp->left) temp->left = new Node();
                temp = temp->left;
            } else {
                if (!temp->right) temp->right = new Node();
                temp = temp->right;
            }
        }
    }

    int max_xor(int val) {
        Node *temp = root;
        int curr = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (bit == 0) {
                if (temp->right) {
                    curr |= (1 << i);
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->left) {
                    curr |= (1 << i);
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }
        return curr;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    // Step 1: prefix XORs from left to right
    vector<int> prefix(n), leftMax(n), rightMax(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] ^ arr[i];

    // Step 2: Left max XOR subarrays
    Trie leftTrie;
    leftTrie.insert(0);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr ^= arr[i];
        leftMax[i] = (i == 0) ? leftTrie.max_xor(curr) : max(leftMax[i - 1], leftTrie.max_xor(curr));
        leftTrie.insert(curr);
    }

    // Step 3: Right max XOR subarrays
    Trie rightTrie;
    rightTrie.insert(0);
    curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        curr ^= arr[i];
        if (i == n - 1)
            rightMax[i] = rightTrie.max_xor(curr);
        else
            rightMax[i] = max(rightMax[i + 1], rightTrie.max_xor(curr));
        rightTrie.insert(curr);
    }

    // Step 4: Combine left[i] and right[i + 1] to get max sum
    int result = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        result = max(result, leftMax[i] + rightMax[i + 1]);
    }

    cout << result << endl;
    return 0;
}
