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
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<Node* , pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* node=p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        // Print the values stored in nodes
cout << "Contents of nodes:\n";
for(auto &p : nodes){
    for(auto &q : p.second){
        for(int val : q.second){
            cout << val << " ";
        }
    }
    cout << endl;      // New line after each vertical column
}
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(11);
    root->right->left = new Node(9);
    root->right->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right  = new Node(6);
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