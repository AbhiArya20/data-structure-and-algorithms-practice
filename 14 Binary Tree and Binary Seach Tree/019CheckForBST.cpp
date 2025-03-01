#include<bits/stdc++.h>
using namespace std;

// GFG - Check for BST

class Solution{
    pair<int,pair<int,int>> postOrder(Node* root) {
        if(!root)
           return {true,{INT_MAX,INT_MIN}};
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);
        if(!left.first || !right.first)
           return {false,{0,0}};
        if(root->data>left.second.second && root->data<right.second.first)
           return {true,{min(root->data,min(left.second.first,right.second.first)),max(root->data,max(left.second.second,right.second.second))}};
        return {false,{0,0}};
    }
    public:
    bool isBST(Node* root){
        return postOrder(root).first; 
    }
};