#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool func(TreeNode* Left,TreeNode* Right){
        if(Left==NULL || Right==NULL) return Left==Right;
        if(Left->val != Right->val) return false;
        return func(Left->left,Right->right) && func(Left->right,Right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || func(root->left,root->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);
    cout << (result ? "The tree is symmetric." : "The tree is not symmetric.") << endl;

    return 0;
}