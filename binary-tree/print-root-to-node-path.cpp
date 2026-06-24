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
    bool getpath(Node* root, int target, vector<int>& path) {
        if (!root) return false;
        path.push_back(root->data);
        if (root->data == target) return true;
        if (getpath(root->left, target, path) || getpath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
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
    vector<int> path;
    int target = 6; // Change this to the target node value you want to find the path for
    if (sol.getpath(root, target, path)) {
        cout << "Path from root to node " << target << ": ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "Node " << target << " not found in the tree." << endl;
    }

    return 0;
}
