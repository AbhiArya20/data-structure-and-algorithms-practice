#include<bits/stdc++.h>
using namespace std;

// GFG - Iterative Inorder Traversal

class Solution{ // No Change in tree
    public:
    vector<int> inOrder(Node* root){
       vector<int> ans;
       if(!root)
            return ans;
       stack<Node*> st;
       Node* cur = root;
       while(true){
            if(!cur){
                if(st.empty())
                    break;
                ans.push_back(st.top()->data);
                if(st.top()->right)
                    cur = st.top()->right;
                st.pop();
            }
            else{
                st.push(cur);
                cur = cur->left;
            }
       }
       return ans;
    }
};

class Solution { // Recursive
    void inorder(Node* root, vector<int> &ans){
        if(!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};



// GFG - Iterative Postorder Traversal

class Solution { // Iterative - Change in tree
public:
    vector<int> postOrder(Node* root){
        vector<int> ans;
        if(!root)
            return ans;
        stack<Node*> st;
        st.push(root);
        Node* cur;
        while(!st.empty()){
            cur = st.top();
            if(cur->left){
                st.push(cur->left);
                cur->left = NULL;
            }else if(cur->right){
                st.push(cur->right);
                cur->right = NULL;
            }else{
                ans.push_back(cur->data);
                st.pop();
            }
        }
        return ans;
    }
};


class Solution { // Recursive
    void postorder(Node* root, vector<int> &ans){
        if(!root)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->data);
    }
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};



// GFG - Iterative Preorder Traversal


class Solution { // Iterative - Change in tree
public:
    vector<int> preOrder(Node* root){
        vector<int> ans;
        if(!root)
            return ans;
        stack<Node*> st;
        st.push(root);
        ans.push_back(root->data);
        Node* cur;
        while(!st.empty()){
            cur = st.top();
            if(cur->left){
                ans.push_back(cur->left->data);
                st.push(cur->left);
                cur->left = NULL;
            }else if(cur->right){
                ans.push_back(cur->right->data);
                st.push(cur->right);
                cur->right = NULL;
            }else{
                st.pop();
            }
        }
        return ans;
    }
};


class Solution{ // More efficient - No change in tree
    public:
    vector<int> preOrder(Node* root){
       vector<int> ans;
       stack<Node*> st;
       Node* cur = root;
       st.push(root);
       while(!st.empty()){
           if(cur == NULL){
               cur = st.top();
           }else{
                if(cur->right)
                    st.push(cur->right);
                ans.push_back(cur->data);
                cur = cur->left;
                if(cur==NULL){
                    cur = st.top();
                    st.pop();
                }
           }
       }
       return ans;
    }
};

class Solution { // Recursive
    void preorder(Node* root, vector<int> &ans){
        if(!root)
            return;
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};




// GFG - All Traversal In Single Visit

class Solution{ // recursive
    void traversal(Node* root, vector<int> &pre, vector<int> &in, vector<int> &post){
        if(!root)
            return;
        pre.push_back(root->data);
        traversal(root->left,pre,in,post);
        in.push_back(root->data);
        traversal(root->right,pre,in,post);
        post.push_back(root->data);
    }
    public:
    vector<vector<int>> allTraversal(Node* root){
        vector<int> pre, in, post;
        traversal(root,pre,in,post);
        return {pre,in,post};
    }
};

class Solution{ // Iterative
    public:
    vector<vector<int>> postOrder(Node* root){
       vector<int> pre,in,pos;
       if(!root)
            return pre;
       stack<pair<Node*,int>> st;
       Node* cur = NULL;
       st.push({root,0});
       while(!st.empty()){
           cur = st.top().first;
           int step = st.top().second;
           st.pop();
           if(step==0){
               pre.push_back(cur->data);
               st.push({cur,1});
               if(cur->left)
                    st.push({cur->left,0});
           }else if(step == 1){
               in.push_back(cur->data);
               st.push({cur,2});
               if(cur->right)
                    st.push({cur->right,0});
           }
           else{
                pos.push_back(cur->data);
           }
       }
       return {pre,in,pos};
    }
};



// Morris Travesal - Inorder and Preorder

class Solution{
    public:
    vector<int> morrisTraversal(TreeNode* root){
        vector<int> pre, in;
        if(!root)
            return in;
        TreeNode* cur = root;
        while(cur){
            if(!cur->left){
                pre.push_back(cur->val);
                in.push_back(cur->val);
                cur = cur->right;
            }else{
                auto temp = cur->left;
                while(temp->right && temp->right != cur){
                    temp = temp->right;
                }
                if(temp->right == cur){
                    temp->right = NULL;
                    in.push_back(cur->val);
                    cur = cur->right;
                }else{
                    pre.push_back(cur->val);
                    temp->right = cur;
                    cur = cur->left;
                }
            }
        }
        return pre;
    }
};