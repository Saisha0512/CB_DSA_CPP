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

TreeNode* buildBST(vector<int> nodes, int s, int e){
    // Base Case : 
    if (s > e){
        return NULL;
    }

    // Recursive Case : 
    int mid = (s + e)/2;
    TreeNode *root = new TreeNode(nodes[mid]);
    root -> left = buildBST(nodes, s, mid - 1);
    root -> right = buildBST(nodes, mid + 1, e);
    return root;
}

void preorder(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a ++){
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; i ++){
            cin >> nodes[i];
        }
        TreeNode *root = buildBST(nodes, 0, nodes.size() - 1);
        preorder(root);
        cout << endl;
    }
    return 0;
}