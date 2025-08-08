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

TreeNode* insertInBST(TreeNode *root, int data){
    // Base Case :
    if (root == NULL){
        return new TreeNode(data);
    }

    // Recursive Case : 
    if (data <= root -> val){
        root -> left = insertInBST(root -> left, data);
    }
    else {
        root -> right = insertInBST(root -> right, data);
    }
    return root;
}

TreeNode* buildBST(int n){
    TreeNode *root = NULL;
    for (int i = 0; i < n; i ++){
        int data;
        cin >> data;
        root = insertInBST(root, data);
    }
    return root;
}

TreeNode* lcaBST(TreeNode *root, int p, int q){
    // Base Case : 
    if (root == NULL){
        return NULL;
    }

    // Recursive Case : 
    if (p < root -> val && q < root -> val){
        return lcaBST(root -> left, p, q);
    }

    if (p > root -> val && q > root -> val){
        return lcaBST(root -> right, p, q);
    }

    return root;
}

int main(){
    int n;
    cin >> n;
    TreeNode *root = buildBST(n);
    int p, q;
    cin >> p >> q;
    TreeNode *lca = lcaBST(root, p, q);
    cout << lca -> val << endl;
    return 0;
}