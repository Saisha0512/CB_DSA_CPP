# include <iostream>
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

TreeNode* buildTreeBoolean(){
    int x;
    cin >> x;
    TreeNode *root = new TreeNode(x);
    string lchild, rchild;
    cin >> lchild;
    if (lchild == "true"){
        root -> left = buildTreeBoolean();
    }
    cin >> rchild;
    if (rchild == "true"){
        root -> right = buildTreeBoolean();
    }

    return root;
}

void printBFS(TreeNode* root){
    if (root == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        TreeNode *curr = q.front();
        if (curr == NULL){
            cout << endl;
            q.pop();
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << curr -> val << " ";
            if (curr -> left){
                q.push(curr -> left);
            }
            if (curr -> right){
                q.push(curr -> right);
            }
        }
    }
}

int sum(TreeNode* root){
    // Base Case : 
    if (root == NULL){
        return 0;
    }

    // Recursive Case : 
    return root -> val + sum(root -> left) + sum(root -> right);
}

int main(){
    TreeNode *root = buildTreeBoolean();
    cout << sum(root) << endl;

    return 0;
}