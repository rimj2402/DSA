#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};
class Solution{
    public: 
    vector<int> bottomView(TreeNode* root){
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second;
            mp[x]=node->data;
            if(node->left){
                q.push({node->left,x-1});
            }
            if(node->right){
                q.push({node->right,x+1});
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
int main(){
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
    vector<int> result = sol.bottomView(root);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}