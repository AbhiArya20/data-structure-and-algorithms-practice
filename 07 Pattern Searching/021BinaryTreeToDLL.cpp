#include<bits/stdc++.h>
using namespace std;

// GFG - Binary Tree To DLL

class Solution{
    void inorderTraversal(Node* root, vector<Node*> &inorder){
        if(!root)
            return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root);
        inorderTraversal(root->right,inorder);
    }
    public: 
    Node * bToDLL(Node *root){
        vector<Node*> inorder;
        inorderTraversal(root,inorder);
        int n = inorder.size();
        if(n==1)
            return inorder[0];
        for(int i = 0; i<n; i++){
            if(i==0){
                inorder[i]->left = NULL;
                inorder[i]->right = inorder[i+1];
            }
            else if(i==n-1){
                inorder[i]->right = NULL;
                inorder[i]->left = inorder[i-1];
            }else{
                inorder[i]->left = inorder[i-1];
                inorder[i]->right = inorder[i+1];
            }
        }
        return inorder[0];
    }
};



class Solution{ // Optimized
    Node* head;
    void inorderTraversal(Node* root){
        if(!root)
            return;
        inorderTraversal(root->right);
        root->right = head;
        if(head!=NULL)
            head->left = root;
        head = root;
        inorderTraversal(root->left);
    }
    public: 
    Node * bToDLL(Node *root){
        head = NULL;
        inorderTraversal(root);
        return head;
    }
};