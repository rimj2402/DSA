#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    int diameter(Node* root, int &d){
        if(root==NULL) return 0;
        int lh=diameter(root->left,d);
        int rh=diameter(root->right,d);
        d=max(d,lh+rh);
        return max(lh,rh)+1;
    }
    int func(Node* root){
        int d=0;
        diameter(root,d);
        return d;
    }
};

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    root->right->right->right=new Node(7);
    Solution ob;
    cout<<"Diameter is:"<<ob.func(root);
}