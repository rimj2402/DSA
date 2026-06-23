#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}

};

class Solution {
public:
    void leftboundary(TreeNode* root, vector<int> &res){
        if(!root) return;
        TreeNode* cur=root->left;
        while(cur){
            if(!isleaf(cur)) res.push_back(cur->val);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
    }
    void leaf(TreeNode* root,vector<int> &res){
        if(!root) return;
        if(isleaf(root)) res.push_back(root->val);
        leaf(root->left,res);
        leaf(root->right,res);
    }
    void rightboundary(TreeNode* root,vector<int> &res){
        if(!root) return;
        TreeNode* cur=root->right;
        vector<int>tmp;
        while(cur){
            if(!isleaf(cur)) tmp.push_back(cur->val);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.push_back(tmp[i]);
        }
    }
    vector<int> boundary(TreeNode* root){
        if(!root) return {};
        vector<int>res;
        if(!isleaf(root)) res.push_back(root->val);
        leftboundary(root,res);
        leaf(root,res);
        rightboundary(root,res);
        return res;
    }

    bool isleaf(TreeNode* root){
        return !root->left && !root->right;
    }

    int main(){
        TreeNode* root=new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(3);
        root->left->left=new TreeNode(4);
        root->left->right=new TreeNode(5);
        root->right->left=new TreeNode(6);
        root->right->right=new TreeNode(7);
        Solution s;
        vector<int>res=s.boundary(root);
        for(int i:res) cout<<i<<" ";
    }   