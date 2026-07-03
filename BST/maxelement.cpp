#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxValue(TreeNode* root){
        if(root==NULL) return -1;
        TreeNode* cur=root;
        while(cur->right != nullptr){
            cur=cur->right;
        }
        return cur->val;
    }
};

int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    int maxValueInBST = sol.maxValue(root);
    cout << "The maximum value in the BST is: " << maxValueInBST << endl;

    // Clean up memory (delete the tree nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}