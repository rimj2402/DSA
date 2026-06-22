#include<bits/stdc++.h>
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
    int height(Node* root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        if(lh==-1) return -1;
        int rh=height(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(Node* root){
        return height(root)!=-1;
    }
};

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    // root->right->right=new Node(6);
    // root->right->right->right=new Node(7);
    
    Solution ob;
    if(ob.isBalanced(root)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}