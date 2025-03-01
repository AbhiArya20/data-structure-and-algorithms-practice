#include<bits/stdc++.h>
using namespace std;

// LeetCode - 99

class Solution {
    void inOrder(TreeNode* root, vector<TreeNode*> &inorder){
        if(!root)
            return;
        inOrder(root->left, inorder);
        inorder.push_back(root);
        inOrder(root->right,inorder);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        inOrder(root,inorder);
        int n = inorder.size();
        int first = -1;
        int second = -1;
        for(int i = 1; i<n; i++){
            if(inorder[i]->val<inorder[i-1]->val){
                if(first == -1){
                    first = i;
                }
                else {
                    second = i;
                }
            }
        }
        if(second == -1)
            return swap(inorder[first-1]->val, inorder[first]->val);
        swap(inorder[first-1]->val, inorder[second]->val);
    }
};



class Solution {
    void inOrder(TreeNode* root,TreeNode* &previous,TreeNode* &first, TreeNode* &second, TreeNode* &prev){
        if(!root)
            return;
        inOrder(root->left,previous,first,second,prev);
        if(previous && previous->val>root->val){
            if(first == NULL){
                prev = previous;
                first = root;
            }else{
                second = root;
            }
        }
        previous = root;
        inOrder(root->right,previous,first,second,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev= NULL;
        TreeNode* previous = NULL;
        inOrder(root,previous,first,second,prev);
        if(second == NULL)
            swap(prev->val,first->val);
        else
            swap(prev->val,second->val);
    }
};