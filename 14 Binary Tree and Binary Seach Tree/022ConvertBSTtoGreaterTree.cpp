#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1038 && 538

class Solution {
    void inorder(TreeNode* root,vector<TreeNode*> &inorders){
        if(!root)
            return;
        inorder(root->left,inorders);
        inorders.push_back(root);
        inorder(root->right,inorders);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> inorders;
        inorder(root,inorders);
        int n = inorders.size();
        for(int i = n-2; i>=0; i--){
            inorders[i]->val += inorders[i+1]->val;
        }
        return root;
    }
};
