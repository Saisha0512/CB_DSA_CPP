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

bool checkIdenticalTree(TreeNode* root1, TreeNode* root2){
    // Base Case : 
    if (root1 == NULL && root2 == NULL){
        return true;
    }

    // Recursive Case : 
    if (root1 == NULL || root2 == NULL){
        return false;
    }
    bool ltree = checkIdenticalTree(root1 -> left, root2 -> left);
    bool rtree = checkIdenticalTree(root1 -> right, root2 -> right);
    return (ltree && rtree);
}

int main(){
    TreeNode *root1 = buildTreeBoolean();
    TreeNode *root2 = buildTreeBoolean();
    if (checkIdenticalTree(root1, root2)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}