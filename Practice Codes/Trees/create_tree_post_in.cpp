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

TreeNode* createTree(int post[], int in[], int n, int s, int e){
    static int i = n - 1;
    // Base Case : 
    if (s > e){
        return NULL;
    }

    // Recursive Case : 
    TreeNode *root = new TreeNode(post[i --]);
    int idx = -1;
    for (int j = s; j <= e; j ++){
        if (in[j] == root -> val){
            idx = j;
            break;
        }
    }
    root -> right = createTree(post, in , n, idx + 1, e);
    root -> left = createTree(post, in, n, s, idx - 1);
    return root;
}

void printTree(TreeNode* root){
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
    cout << root -> val;
    if (root -> right){
        cout << " <= " << root -> right -> val << endl;
    }
    else {
        cout << " <= END" << endl;
    }
    printTree(root -> left);
    printTree(root -> right);
}

int main(){
    int n;
    cin >> n;
    int post[n];
    for (int i = 0; i < n; i ++){
        cin >> post[i];
    }
    int m;
    cin >> m;
    int in[m];
    for (int i = 0; i < m; i ++){
        cin >> in[i];
    }
    TreeNode *root = createTree(post, in, n, 0, n - 1);
    printTree(root);
    return 0;
}