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

void kthLargest(TreeNode *root, int &k, int &result){
    // Base Case : 
    if (root == NULL || k <= 0){
        return;
    }
    
    // Recursive Case : 
    kthLargest(root -> right, k, result);
    k --;
    if (k == 0){
        result = root -> val;
        return;
    }
    kthLargest(root -> left, k, result);
}

int main(){
    int n;
    cin >> n;
    TreeNode* root = buildBST(n);
    int k;
    cin >> k;
    int result = -1;
    kthLargest(root, k, result);
    if (result != -1){
        cout << result;
    }
    return 0;
}