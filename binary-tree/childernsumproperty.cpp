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
    void changetree(Node* root){
        if(root==NULL) return;
        int child=0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;
        if(child> root->data) root->data=child;
        else{
            if(root->left) root->left->data=root->data;
            if(root->right) root->right->data=root->data;
        }
        changetree(root->left);
        changetree(root->right);
        int tot=0;
        if(root->left) tot+=root->left->data;
        if(root->right) tot+=root->right->data;
        if(root->left || root->right) root->data=tot;
    }
};

int main(){
    Node* root=new Node(50);
    root->left=new Node(7);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(5);
    root->right->left=new Node(1);
    root->right->right=new Node(30);

    Solution sol;
    sol.changetree(root);

    // Function to print the tree in-order for verification
    function<void(Node*)> printInOrder = [&](Node* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    };

    cout << "Modified tree in-order: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
