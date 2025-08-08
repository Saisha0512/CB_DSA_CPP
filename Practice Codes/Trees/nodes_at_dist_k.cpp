# include <iostream>
# include <vector>
# include <algorithm>
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

TreeNode* createTree(int pre[], int in[], int s, int e, int &i){
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
    root -> left = createTree(pre, in, s, idx - 1, i);
    root -> right = createTree(pre, in, idx + 1, e, i);
    return root;
}

void printkthLevel(TreeNode *root, int level, vector<int> &res){
    // Base Case : 
    if (root == NULL){
        return;
    }
    if (level == 0){
        res.push_back(root -> val);
        return;
    }

    // Recursive Case : 
    printkthLevel(root -> left, level - 1, res);
    printkthLevel(root -> right, level - 1, res);
}

int atKthDist(TreeNode* root, int target, int k, vector<int> &res){
    // Base Case : 
    if (root == NULL){
        return -1;
    }
    if (root -> val == target){
        printkthLevel(root, k, res);
        return 1;
    }

    // Recursive Case : 
    int ld = atKthDist(root -> left, target, k, res);
    if (ld != -1){
        if (ld == k){
            res.push_back(root -> val);
        }
        else {
            printkthLevel(root -> right, k - ld - 1, res);
        }
        return ld + 1;
    }
    int rd = atKthDist(root -> right, target, k, res);
    if (rd != -1){
        if (rd == k){
            res.push_back(root -> val);
        }
        else {
            printkthLevel(root -> left, k - rd - 1, res);
        }
        return rd + 1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int pre[n];
    int in[n];
    for (int i = 0; i < n; i ++){
        cin >> pre[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> in[i];
    }
    int i = 0;
    TreeNode *root = createTree(pre, in, 0, n - 1, i);
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        int x, k;
        cin >> x >> k;
        vector<int> res;
        atKthDist(root, x, k, res);
        sort(res.begin(), res.end());
        if (res.size() == 0){
            cout << 0;
        }
        for (int j = 0; j < res.size(); j ++){
            cout << res[j] << " ";
        }
        cout << endl;
    }
    return 0;
}