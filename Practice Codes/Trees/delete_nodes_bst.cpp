# include <iostream>
# include <vector>
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

TreeNode* deleteNode(TreeNode *root, int data){
    // Base Case : 
    if (root == NULL){
        return NULL;
    }

    // Recursive Case : 
    else if (data < root -> val){
        root -> left = deleteNode(root -> left, data);
        return root;
    }
    else if (data == root -> val){
        // 3 CASES : 
        // 1. Root with 0 children;
        if (root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // 2. Root with 1 child : 
        if (root -> left != NULL && root -> right == NULL){
            TreeNode *temp = root -> left;
            delete root;
            return temp;
        }
        if (root -> left == NULL && root -> right != NULL){
            TreeNode *temp = root -> right;
            delete root;
            return temp;
        }

        // 3. Root with 2 children : 
        TreeNode *replace = root -> right;
        while (replace -> left != NULL){
            replace = replace -> left;
        }
        root -> val = replace -> val;
        root -> right = deleteNode(root -> right, replace -> val);
        return root;
    }
    
    else { 
        root -> right = deleteNode(root -> right, data);
        return root;
    }
}

void printPreorder(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    cout << root -> val << " ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n;
        cin >> n;
        TreeNode *root = buildBST(n);
        int m;
        cin >> m;        
        for (int i = 0; i < m; i ++){
            int el;
            cin >> el;
            root = deleteNode(root, el);
        }
        printPreorder(root);
        cout << endl;
    }
    return 0;
}