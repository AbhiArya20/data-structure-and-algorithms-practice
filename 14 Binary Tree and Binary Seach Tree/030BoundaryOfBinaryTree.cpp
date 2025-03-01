#include<bits/stdc++.h>
using namespace std;

// GFG - Boundary Traversal of binary tree

class Solution {
    bool isLeaf(Node *root){
        return (!root->left) && (!root->right);
    }
    void getLeft(Node *root, vector<int> &ans){
        auto cur = root->left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void getLeaf(Node *root,vector<int> &ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        getLeaf(root->left, ans);
        getLeaf(root->right, ans);
    }
    void getRight(Node *root, vector<int> &ans){
        auto cur = root->right;
        vector<int> res;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        reverse(res.begin(), res.end());
        ans.insert(ans.end(), res.begin(),res.end());
    }
    public:
    vector<int> boundary(Node* root){
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root))
            ans.push_back(root->data);
        getLeft(root, ans);
        getLeaf(root, ans);
        getRight(root, ans);
        return ans;
    }
};