# include <iostream>
# include <queue>
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

TreeNode* createTree(int pre[], int in[], int s, int e){
    static int i = 0;
    // Base Case : 
    if (s > e){
        return NULL;
    }

    // Recursive Case : 
    TreeNode *root = new TreeNode(pre[i ++]);
    int idx = -1;
    for (int j = s; j <= e; j ++){
        if (in[j] == root -> val){
            idx = j;
            break;
        }
    }
    root -> left = createTree(pre, in, s, idx - 1);
    root -> right = createTree(pre, in, idx + 1, e);
    return root;
}

void printBFS(TreeNode* root){
    if (root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        cout << curr -> val << " ";
        if (curr -> left){
            q.push(curr -> left);
        }
        if (curr -> right){
            q.push(curr -> right);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; i ++){
        cin >> pre[i];
    }
    int in[n];
    for (int i = 0; i < n; i ++){
        cin >> in[i];
    }
    TreeNode *root = createTree(pre, in, 0, n - 1);
    printBFS(root);
    return 0;
}