#include<bits/stdc++.h>
using namespace std;

// GFG - AVL Tree

class AVLTree{
    class Node{
        public:
        int value;
        int height;
        Node* left;
        Node* right;
        Node(int val){
            height = 1;
            value = val;
            left = NULL;
            right = NULL;
        }
    };
    Node* root;
    int height(Node* root){
        if(!root)
            return 0;
        return root->height;
    }
    int getBalance(Node* root){
        if(!root)
            return 0;
        return height(root->left) - height(root->right);
    }
    Node* leftRotate(Node* root){
        Node* newRoot = root->right;
        Node* left = newRoot->left;
        
        newRoot->left = root;
        root->right = left;

        root->height = max(height(root->left), height(root->right))+1;
        newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;
        return newRoot;
    }
    Node* rightRotate(Node* root){
        Node* newRoot = root->left;
        Node* right = newRoot->right;
        newRoot->right = root;
        root->left = right;

        root->height = max(height(root->left), height(root->right))+1;
        newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;
        return newRoot;
    }
    Node* insert(Node* root, int val){
        if(!root)
            return new Node(val);
        if(val<root->value)
            root->left = insert(root->left,val);
        else if(val>root->value)
            root->right = insert(root->right,val);
        else
            return root;
        root->height = 1+max(height(root->left), height(root->right));
        int balance = getBalance(root); 
        if(balance>1){ 
            if(val < root->left->value){
                return rightRotate(root);
            }
            if(val > root->left->value){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if(balance<-1){
            if(val < root->right->value){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            if(val > root->right->value){
                return leftRotate(root);
            }
        }
        return root;
    }
    Node* minValueNode(Node* root){
        while(root->left)
            root = root->left;
        return root;
    }
    Node* erase(Node* root, int val){
        if(!root)
            return root;
        if(val<root->value)
            root->left = erase(root->left,val);
        else if(val>root->value)
            root->right = erase(root->right,val);
        else{
            if(!root->left || !root->right){
                Node* temp = root->left? root->left: root->right;
                if(temp==NULL){
                    temp = root;
                    root = NULL;
                }else{
                    *root = *temp;
                }
                free(temp);
            }else{
                Node* temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = erase(root->right,temp->value);
            }
        }
        if(!root)
            return root;
        root->height = 1+max(height(root->left), height(root->right));
        int balance = getBalance(root);
        if(balance>1){ 
            if(getBalance(root->left)>=0){
                return rightRotate(root);
            }
            if(getBalance(root->left)<0){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if(balance<-1){
            if(getBalance(root->right)>0){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            if(getBalance(root->right)<=0){
                return leftRotate(root);
            }
        }
        return root;
    }
    public: 
    AVLTree(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root,val);
    }
    void erase(int val){
        root = erase(root,val);
    }
};