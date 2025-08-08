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

TreeNode* buildTree(){
    int x;
    cin >> x;
    TreeNode *root = new TreeNode(x);
    string lchild, rchild;
    cin >> lchild;
    if (lchild == "true"){
        root -> left = buildTree();
    }
    else {
        root -> left = NULL;
    }
    cin >> rchild;
    if (rchild == "true"){
        root -> right = buildTree();
    }
    else {
        root -> right = NULL;
    }
    return root;
}

int checkBalanced(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return 0;
    }

    // Recursive Case : 
    int lans = checkBalanced(root -> left);
    if (lans == -1){
        return -1;
    }
    int rans = checkBalanced(root -> right);
    if (rans == -1){
        return -1;
    }

    if (abs(lans - rans) > 1){
        return -1;
    }
    return max(lans, rans) + 1;
}

int main(){
    TreeNode *root = buildTree();
    int ht = checkBalanced(root);
    if (ht != -1){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}