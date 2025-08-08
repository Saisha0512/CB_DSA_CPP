# include <iostream>
# include <vector>
using namespace std;

class TreeNode{
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

void rootToLeaf(TreeNode* root, vector<vector<int>> &res, vector<int> arr, int target){
    // Base Case : 
    if (root == NULL){
        return;
    }
    if (root -> left == NULL && root -> right== NULL && target == root -> val){
        arr.push_back(root -> val);
        res.push_back(arr);
        return;
    }

    // Recursive Case : 
    if (root -> val < target){
        arr.push_back(root -> val);
        rootToLeaf(root -> left, res, arr, target - root -> val);
        rootToLeaf(root -> right, res, arr, target - root -> val);
    }
    return;
}

int main(){
    TreeNode *root = buildTreeBoolean();
    int target;
    cin >> target;
    vector<vector<int>> res;
    vector<int> arr;
    arr.push_back(root -> val);
    rootToLeaf(root -> left, res, arr, target - root -> val);
    rootToLeaf(root -> right, res, arr, target - root -> val);
    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}