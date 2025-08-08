# include <iostream>
# include <vector>
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

TreeNode* buildTreeBoolean(){
    int x;
    cin >> x;
    TreeNode *root = new TreeNode(x);
    string lchild, rchild;
    cin >> lchild;
    if (lchild == "true"){
        root -> left = buildTreeBoolean();
    }
    cin >> rchild;
    if (rchild == "true"){
        root -> right = buildTreeBoolean();
    }
    return root;
}

vector<vector<int>> BFSTraversal(TreeNode *root){
    vector<vector<int>> res;
    vector<int> arr;
    if (root == NULL){
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode *curr = q.front();
        if (curr == NULL){
            q.pop();
            res.push_back(arr);
            arr.clear();
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            q.pop();
            arr.push_back(curr -> val);
            if (curr -> left){
                q.push(curr -> left);
            }
            if (curr -> right){
                q.push(curr -> right);
            }
        }
    }
    return res;
}

int main(){
    TreeNode *root = buildTreeBoolean();
    vector<vector<int>> res = BFSTraversal(root);
    for (int i = 0; i < res.size(); i ++){
        if (i % 2 == 0){
            for (int j = 0; j < res[i].size(); j ++){
                cout << res[i][j] << " ";
            }
        }
        else {
            for (int j = res[i].size() - 1; j >= 0; j --){
                cout << res[i][j] << " ";
            }
        }
    }
    return 0;
}