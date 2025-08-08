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

TreeNode* inorderBST(int in[], int s, int e){
    // Base Case : 
    if (s > e){
        return NULL;
    }

    // Recursive Case : 
    int mid = (s + e)/2;
    TreeNode *root = new TreeNode(in[mid]);
    root -> left = inorderBST(in, s, mid - 1);
    root -> right = inorderBST(in, mid + 1, e);
    return root;
}

void replaceWithSum(TreeNode* root, int &maxsum){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    replaceWithSum(root -> right, maxsum);
    maxsum += root -> val;
    root -> val = maxsum;
    replaceWithSum(root -> left, maxsum);
}

void preorderTraversal(TreeNode* root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    cout << root -> val << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main(){
    int n;
    cin >> n;
    int in[n];
    for (int i = 0; i < n; i ++){
        cin >> in[i];
    }
    TreeNode *root = inorderBST(in, 0, n - 1);
    int maxsum = 0;
    replaceWithSum(root, maxsum);
    preorderTraversal(root);
    return 0;
}