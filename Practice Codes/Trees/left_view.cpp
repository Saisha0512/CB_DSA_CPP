# include <iostream>
# include <vector> 
# include <queue>
using namespace std;

class TreeNode {
public : 
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildBFSTree(){
    int x;
    cin >> x;
    if (x == -1){
        return NULL;
    }
    TreeNode *root = new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        int lchild, rchild;
        cin >> lchild;
        if (lchild == -1){
            curr -> left = NULL;
        }
        else {
            curr -> left = new TreeNode(lchild);
            q.push(curr -> left);
        }
        cin >> rchild;
        if (rchild == -1){
            curr -> right = NULL;
        }
        else {
            curr -> right = new TreeNode(rchild);
            q.push(curr -> right);
        }
    }
    return root;
}

void leftView(TreeNode* root, int currlevel, int &maxlevel){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case :
    if (currlevel > maxlevel){
        cout << root -> val << " ";
        maxlevel = currlevel;
    }
    leftView(root -> left, currlevel + 1, maxlevel);
    leftView(root -> right, currlevel + 1, maxlevel);
}

int main(){
    TreeNode *root = buildBFSTree();
    int maxlevel = 0;
    leftView(root, 1, maxlevel);
    return 0;
}