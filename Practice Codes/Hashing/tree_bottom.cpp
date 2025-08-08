# include <iostream>
# include <queue>
# include <map>
using namespace std;

class TreeNode {
public : 
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
    int d;
    cin >> d;
    if (d == -1){
        return NULL;
    }
    TreeNode *root = new TreeNode(d);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        int lchild, rchild;
        cin >> lchild;
        if (lchild != -1){
            curr -> left = new TreeNode(lchild);
            q.push(curr -> left);
        }
        cin >> rchild;
        if (rchild != -1){
            curr -> right = new TreeNode(rchild);
            q.push(curr -> right);
        }
    }
    return root;
}

void treeBottom(TreeNode *root, int row, int col, map<int, pair<int, int>> &m){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    if (m.count(col) == 0 || row >= m[col].first){
        m[col] = {row, root -> val};
    }

    treeBottom(root -> left, row + 1, col - 1, m);
    treeBottom(root -> right, row + 1, col + 1, m);
}

int main(){
    TreeNode *root = buildTree();
    map<int, pair<int, int>> m;
    int row = 0, col = 0;
    treeBottom(root, row, col, m);
    for (auto p : m){
        cout << p.second.second << " ";
    }
    return 0;
}