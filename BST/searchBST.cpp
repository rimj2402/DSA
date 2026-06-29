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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(val<root->val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int searchValue = 2;
    TreeNode* result = sol.searchBST(root, searchValue);
    
    if (result != nullptr) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Node with value " << searchValue << " not found." << endl;
    }

    return 0;
}