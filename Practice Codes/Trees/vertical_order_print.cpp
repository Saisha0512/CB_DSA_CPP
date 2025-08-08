# include <iostream>
# include <queue>
# include <vector>
# include <map>
using namespace std;

class TreeNode {
public : 
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
	int d;
	cin >> d;
	TreeNode *root = new TreeNode(d);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *f = q.front();
		q.pop();
		int lchild, rchild;
		cin >> lchild >> rchild;

		if(lchild != -1){
			f->left = new TreeNode(lchild);
			q.push(f->left);
		}
		if(rchild != -1){
			f->right = new TreeNode(rchild);
			q.push(f->right);
		}
	}
	return root;
}

void verticalOrderPrint(TreeNode *root, int d, map<int, vector<int>> &m){
    // Base Case : 
    if (root == NULL){
        return;
    }

    // Recursive Case : 
    m[d].push_back(root -> val);
    verticalOrderPrint(root -> left, d - 1, m);
    verticalOrderPrint(root -> right, d + 1, m);
}

int main(){
    int level;
    cin >> level;
    int n = (1 << level) - 1;
    TreeNode *root = buildTree();
    map<int, vector<int>> tree;
    int d = 0;
    verticalOrderPrint(root, d, tree);
    for (auto p : tree){
        for (int x : p.second) {
            cout << x << " ";
        }
    }
    return 0;
}