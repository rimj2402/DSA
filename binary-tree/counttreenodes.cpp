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
    int callh(TreeNode* node,int lh){
        if(node==NULL) return lh;
        lh++;
        return callh(node->left,lh);
    }
    int calrh(TreeNode* node,int rh){
        if(node==NULL) return rh;
        rh++;
        return calrh(node->right,rh);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=(root->left)?callh(root->left,0):0;
        int rh=(root->right)?calrh(root->right,0):0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int nodeCount = sol.countNodes(root);
    cout << "Total number of nodes in the binary tree: " << nodeCount << endl;

    return 0;
}