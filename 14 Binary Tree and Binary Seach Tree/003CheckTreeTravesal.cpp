#include<bits/stdc++.h>
using namespace std;

// GFG - Check Tree Traversal

struct Node{ 
    int val;
    Node* left;
    Node* right;
    Node(int _val){
        val = _val;
        left = NULL;
        right = NULL;
    }
};

class Solution{bool flag = true;
    Node* buildTree(int ps,int pe, int is,int ie,int preorder[], int inorder[]){
        if(ps>pe || is>ie){
            return NULL;
        }
        Node* node = new Node(preorder[ps]);
        int pos = -1;
        
        for(int i = is; i<=ie; i++){
            if(inorder[i]==preorder[ps]){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            flag = false;
            return NULL;
        }
        node->left = buildTree(ps+1,ps+(pos-is),is,pos-1,preorder,inorder);
        node->right = buildTree(ps+(pos-is)+1,pe,pos+1,ie,preorder,inorder);
        return node;
    }
    void postOrder(Node* root, vector<int> &post){
        if(!root)
            return;
        postOrder(root->left, post);
        postOrder(root->right, post);
        post.push_back(root->val);
    }
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	auto root = buildTree(0,N-1,0,N-1,preorder,inorder);
    	vector<int> post;
    	postOrder(root,post);
    	for(int i = 0; i<N; i++){
    	    if(postorder[i]!=post[i])
    	        return false;
    	}
    	return flag;
    } 

};