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

void printSibling(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recrsive Case : 
    if (root -> left && root -> right == NULL){
        cout << root -> left -> val << " ";
        printSibling(root -> left);
    }
    else if (root -> left == NULL && root -> right){
        cout << root -> right -> val << " ";
        printSibling(root -> right);
    }
    else {
        if (root -> right){
            printSibling(root -> right);
        }
        if (root -> left){
            printSibling(root -> left);
        }
    }
}

int main(){
    TreeNode *root = buildTreeBoolean();
    printSibling(root);

    return 0;
}