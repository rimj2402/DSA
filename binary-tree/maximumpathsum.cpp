#include<bits/stdc++.h>
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
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively get the maximum gain from left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // Calculate the price of the current path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the maximum path sum found so far
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum gain if we continue the same path
        return node->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
};
int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    int result = sol.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;
}