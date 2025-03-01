#include<bits/stdc++.h>
using namespace std;

// LeetCode - 450
// GFG - Delete A Node from BST

class Solution {
    TreeNode* getMax(TreeNode* root){
    while(root->right)
        root  = root->right;
    return root;
    }
    TreeNode* deleteNodes(TreeNode* root, int x){
        if(!root)
            return root;
        if(root->val == x){
            if(!root->left && !root->right)
                return NULL;
            if(!root->left && root->right)
                return root->right;
            if(root->left && !root->right)
                return root->left;
            TreeNode* maxNode= getMax(root->left);
            root->val = maxNode->val;
            root->left = deleteNodes(root->left,maxNode->val);
            return root;
        }
        if(root->val>x){
            root->left = deleteNodes(root->left,x);
        }else if(root->val<x){
        root->right = deleteNodes(root->right, x);
        }
        return root;
    }
    public:
    TreeNode *deleteNode(TreeNode *root, int X) {
        return deleteNodes(root,X);
    }
};