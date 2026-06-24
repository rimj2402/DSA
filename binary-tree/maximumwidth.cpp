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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        while(!q.empty()) {
            int size= q.size();
            int p=q.front().second;
            int first ,last;
            for(int i=0;i<size;i++){
                long long cur=q.front().second-p;
                TreeNode* node= q.front().first;
                q.pop();
                if(i==0) first=cur;
                if(i==size-1) last = cur;
                if(node->left) q.push({node->left,cur*2+1});
                if(node->right) q.push({node->right,cur*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int maxWidth = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    return 0;
}