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

void replaceSum(TreeNode *&root, int &sum){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    replaceSum(root -> right, sum);
    int temp = root -> val;
    root -> val = sum;
    sum += temp;
    replaceSum(root -> left, sum);
}

void printTree(TreeNode *root){
    // Base Case :
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    if (root -> left != NULL){
        cout << root -> left -> val << " => ";
    }
    else {
        cout << "END => ";
    }
    cout << root -> val;
    if (root -> right != NULL){
        cout << " <= " << root -> right -> val;
    }
    else {
        cout << " <= END";
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}

int main(){
    int n;
    cin >> n;
    TreeNode *root = buildBST(n);
    int sum = 0;
    replaceSum(root, sum);
    printTree(root);
    return 0;
}