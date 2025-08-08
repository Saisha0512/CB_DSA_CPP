# include <iostream>
# include <queue>
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

TreeNode* buildBFSTree(vector<int> &nodes){
    if (nodes.empty() || nodes[0] == -1){
        return NULL;
    }    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()){
        TreeNode *curr = q.front();
        q.pop();

        // Left Child : 
        if (i < nodes.size() && nodes[i] != -1){
            curr -> left = new TreeNode(nodes[i]);
            q.push(curr -> left);
        }
        i ++;

        // Right Child : 
        if (i < nodes.size() && nodes[i] != -1){
            curr -> right = new TreeNode(nodes[i]);
            q.push(curr -> right);
        }
        i ++;
    }
    return root;
}

void rightView(TreeNode *root, int currlevel, int &maxlevel){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    if (maxlevel < currlevel){
        cout << root -> val << " ";
        maxlevel = currlevel;
    }
    rightView(root -> right, currlevel + 1, maxlevel);
    rightView(root -> left, currlevel + 1, maxlevel);
}

int main(){
    vector<int> nodes;
    int x;
    cin >> x;
    nodes.push_back(x);
    while (cin >> x){
        nodes.push_back(x);
    }
    TreeNode *root = buildBFSTree(nodes);
    int maxlevel = 0;
    rightView(root, 1, maxlevel);
    return 0;
}