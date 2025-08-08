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

class Pair {
public : 
    int height;
    bool balanced;
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

Pair isBalanced(TreeNode* root){
    Pair p;
    // Base Case : 
    if (root == NULL){
        p.height = 0;
        p.balanced = true;
        return p;
    }

    // Recursive Case : 
    Pair ltree = isBalanced(root -> left);
    Pair rtree = isBalanced(root -> right);
    p.height = max(ltree.height, rtree.height) + 1;
    if (abs(ltree.height - rtree.height) <= 1 && ltree.balanced && rtree.balanced){  
        p.balanced = true;
    }
    else {
        p.balanced = false;
    }
    return p;
}

int main(){
    TreeNode *root = buildTreeBoolean();
    Pair p = isBalanced(root);
    if (p.balanced){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}