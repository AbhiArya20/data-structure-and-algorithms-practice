#include<bits/stdc++.h>
using namespace std;

//GFG - Is Binary Tree Heap

class Solution {
  public:
    bool isHeap(Node* root) {
        if(!root)
            return true;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int flag = false;
            while(size--){
                auto front = q.front();
                q.pop();
                if((!front->left && !front->right) || (root->left && !root->right))
                    flag = true;
                if(!front->left && front->right)
                    return false;
                if(front->left){
                    if(front->data<front->left->data)
                        return false;
                    q.push(front->left);
                }
                if(front->right){
                    if(front->data<front->right->data)
                        return false;
                    q.push(front->right);
                }
            }
            if(q.size() && flag)
                return false;
        }
        return true;
    }
};