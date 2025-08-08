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
    while (!q.empty()){
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
            arr.push_back(curr -> val);
            q.pop();
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

void printBFSTraversal(vector<vector<int>> res){
    for (int i = 0; i < res.size(); i ++){
        if (i == 0){
            cout << "[";
        }
        cout << "[";
        for (int j = 0; j < res[i].size(); j ++){
            cout << res[i][j];
            if (i == res.size() - 1 && j == res[i].size() - 1){
                cout << "]]";
            }
            else if (j == res[i].size() - 1){
                cout << "], ";
            }
            else {
                cout << ", ";
            }
            
        }
    }
}

int main(){
    TreeNode *root = buildTreeBoolean();
    vector<vector<int>> res = BFSTraversal(root);
    printBFSTraversal(res);
    return 0;
}