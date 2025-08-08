# include <iostream>
# include <queue>
# include <vector>
using namespace std;

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    queue<TreeNode*> nodeQueue;
    TreeNode* root = new TreeNode(values[0]);
    nodeQueue.push(root);
    size_t index = 1;

    while (!nodeQueue.empty() && index < values.size()) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (index < values.size() && values[index] != -1) {
            node->left = new TreeNode(values[index]);
            nodeQueue.push(node->left);
        }
        index++;

        if (index < values.size() && values[index] != -1) {
            node->right = new TreeNode(values[index]);
            nodeQueue.push(node->right);
        }
        index++;
    }

    return root;
}

vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> arr;
    if (root == NULL){
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        TreeNode *curr = q.front();
        if (curr == NULL){
            q.pop();
            res.push_back(arr);
            arr.clear();
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            arr.push_back(curr -> val);
            q.pop();
            if (curr -> left){
                q.push(curr -> left);
            }
            if (curr -> right){
                q.push(curr -> right);
            }
        }
    }
    return res;
}

int main() {
    vector<int> values;
    string input;

   
    while (getline(cin, input)) {
        if (input == "done") break;
        stringstream ss(input);
        int num;
        while (ss >> num) {
            values.push_back(num);
        }
    }

    TreeNode* root = buildTree(values);
    vector<vector<int>> levels = levelOrderTraversal(root);

    for (const auto& level : levels) {
        for (int n : level) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
