#include<bits/stdc++.h>
using namespace std;

// LeetCode - 105
// GFG - Construct Tree from Inorder & Preorder

class Solution {
    TreeNode* inorderTraversal(int ps, int pe,int is, int ie,vector<int>& preorder, vector<int>& inorder){
        if(ps>pe)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int idx = -1;
        for(int i = is;  i<=ie; i++){
            if(inorder[i]==preorder[ps]){
                idx = i;
                break;
            }
        }
        int val = idx - is;
        root->left = inorderTraversal(ps+1,ps+val,is,idx-1,preorder,inorder);
        root->right = inorderTraversal(ps+val+1,pe,idx+1,ie,preorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return inorderTraversal(0,n-1,0,n-1,preorder,inorder);
    }
};



// LeetCode - 106
// GFG - Tree from Postorder and Inorder
class Solution {
    TreeNode* inorderTraversal(int ps, int pe,int is, int ie,vector<int>& postorder, vector<int>& inorder){
        if(ps>pe)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int idx = -1;
        for(int i = is;  i<=ie; i++){
            if(inorder[i]==postorder[pe]){
                idx = i;
                break;
            }
        }
        int val = idx - is;
        root->left = inorderTraversal(ps,ps+val-1,is,idx-1,postorder,inorder);
        root->right = inorderTraversal(ps+val,pe-1,idx+1,ie,postorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return inorderTraversal(0,n-1,0,n-1,postorder,inorder);
    }
};