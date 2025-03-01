#include<bits/stdc++.h>
using namespace std;

// LeetCode - 236

class Solution {
    TreeNode* postOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q)
            return root;
        auto left = postOrder(root->left, p, q);
        auto right = postOrder(root->right, p, q);
        if(left && right)
            return root;
        if(left)
            return left;
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postOrder(root, p, q);
    }
};


// LeetCode - 235

class Solution {
    TreeNode* postOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val>q->val)
            return postOrder(root->left, p, q);
        if(root->val<p->val)
            return postOrder(root->right, p, q);
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val>q->val)
            swap(p,q);
        return postOrder(root, p, q);
    }
};



// LeetCode - 1123,865

class Solution {
    TreeNode* postOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q)
            return root;
        auto left = postOrder(root->left, p, q);
        auto right = postOrder(root->right, p, q);
        if(left && right)
            return root;
        if(left)
            return left;
        return right;
    }
    pair<TreeNode*,TreeNode*> deapestNodes(TreeNode* root){
        vector<TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp.push_back(front);
            }
            ans = temp;
        }
        return {ans[0], ans[ans.size()-1]};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto pair = deapestNodes(root);  
        if(pair.first == pair.second)
            return pair.first;
        return postOrder(root,pair.first, pair.second);
    }
};