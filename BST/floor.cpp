#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
    int floor(TreeNode* root,int key){
        int ans=-1;
        while(root!=NULL){
            
            if(root->val==key) return root->val;
            
            if(root->val>key) root=root->left;
            else {
                ans=root->val;
                root=root->right;
                
            }
        }
        return ans;
    }
};

int main(){
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    Solution sol;
    int key = 7;
    int floorValue = sol.floor(root, key);
    if (floorValue != -1) {
        cout << "The floor value of " << key << " in the BST is: " << floorValue << endl;
    } else {
        cout << "There is no floor value for " << key << " in the BST." << endl;
    }
    

    return 0;
}