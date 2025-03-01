#include<bits/stdc++.h>
using namespace std;

// GFG - Min distance between two given nodes of a Binary Tree


class Solution{
    int LCA(Node* root, int a, int b){
        if(!root)
            return -1;
        if(root->data == a || root->data == b)
            return root->data;
        auto left = LCA(root->left,a,b);
        auto right = LCA(root->right,a,b);
        if(left!=-1 && right!=-1){
            return root->data;
        }
        if(left!=-1)
            return left;
        return right;
    }
    int depth(Node* root, int val, int dept){
        if(!root)
            return -1;
        if(root->data==val)
            return dept;
        auto left = depth(root->left,val,dept+1);
        auto right = depth(root->right,val,dept+1);
        int ans = (left!=-1)?left:right;
        return ans;
    }
    public:
    int findDist(Node* root, int a, int b) {
        auto lca = LCA(root,a,b);
        int da = depth(root,a,0);
        int db = depth(root,b,0);
        int dl = depth(root,lca,0);
        return da+db-2*dl;
    }
};
