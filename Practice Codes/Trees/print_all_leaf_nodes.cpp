# include <iostream>
# include <queue>
using namespace std;

class TreeNode{
public : 
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTreeBFS(){
    int x;
    cin >> x;
    if (x == -1){
        return NULL;
    }

    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(x);
    q.push(root);
    while (!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        int a, b;
        cin >> a >> b;
        if (a != -1){
            curr -> left = new TreeNode(a);
            q.push(curr -> left);
        }
        if (b != -1){
            curr -> right = new TreeNode(b);
            q.push(curr -> right);
        }
    }
    return root;
}

void printBFS(TreeNode* root){
    if (root == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        TreeNode *curr = q.front();
        if (curr == NULL){
            cout << endl;
            q.pop();
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << curr -> val << " ";
            if (curr -> left){
                q.push(curr -> left);
            }
            if (curr -> right){
                q.push(curr -> right);
            }
        }
    }
}

void printLeafNodes(TreeNode *root){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    if (root -> left == NULL && root -> right == NULL){
        cout << root -> val << " ";
        return;
    }
    printLeafNodes(root -> left);
    printLeafNodes(root -> right);
}

int main(){
    TreeNode *root = buildTreeBFS();
    printLeafNodes(root);

    return 0;
}