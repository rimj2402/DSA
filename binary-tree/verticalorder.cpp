#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};
class Solution{
public:
    vector<vector<int>> verticalOrder(Node* root){
        vector<vector<int>> res;
        if(!root) return res;
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int hd = p.second;
            mp[hd].push_back(node->data);
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);
    for(const auto& level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}