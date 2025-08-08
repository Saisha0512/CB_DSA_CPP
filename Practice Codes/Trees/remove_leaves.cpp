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

TreeNode* removeLeaves(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return NULL;
    }

    // Recursive Case : 
    if (root -> left == NULL && root -> right == NULL){
        delete root;
        return NULL;
    }

    root -> left = removeLeaves(root -> left);
    root -> right = removeLeaves(root -> right);

    return root;
}

void printPreorder(TreeNode* root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    if (root -> left){
        cout << root -> left -> val << " => ";
    }
    else {
        cout << "END => ";
    }
    cout << root -> val << " <= ";
    if (root -> right){
        cout << root -> right -> val << endl;
    }
    else {
        cout << "END" << endl;
    }

    printPreorder(root -> left);
    printPreorder(root -> right);
}

int main(){
    TreeNode *root = buildTreeBoolean();
    root = removeLeaves(root);
    printPreorder(root);

    return 0;
}