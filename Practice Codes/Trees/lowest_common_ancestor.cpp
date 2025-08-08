# include <iostream>
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

TreeNode* lca(TreeNode* root, int x, int y){
    // Base Case : 
    if (root == NULL){
        return NULL;
    }

    // Recursive Case : 
    if (root -> val == x || root -> val == y){
        return root;
    }
    TreeNode *lans = lca(root -> left, x, y);
    TreeNode *rans = lca(root -> right, x, y);
    if (lans != NULL && rans != NULL){
        return root;
    }
    if (lans != NULL){
        return lans;
    }
    return rans;
}

int main(){
    TreeNode *root = buildTreeBoolean();
    int x, y;
    cin >> x >> y;
    TreeNode *res = lca(root, x, y);
    if (res){
        cout << res -> val;
    }
    else {
        cout << "NULL";
    }
    return 0;
}