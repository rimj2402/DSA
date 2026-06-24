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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* node=p.first;
            int level=p.second;
            mp[level]=node->val;
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right  = new TreeNode(6);

    Solution sol;
    vector<int> result = sol.rightSideView(root);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}