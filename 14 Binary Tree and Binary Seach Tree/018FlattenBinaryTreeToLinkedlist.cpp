#include<bits/stdc++.h>
using namespace std;

// LeetCode - 114
// GFG - Flatten binary tree to linked list

class Solution {
    TreeNode* prev;
    void postOrder(TreeNode* root){
        if(!root)
            return;
        postOrder(root->right);
        postOrder(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        prev = NULL;
        postOrder(root);
    }
};