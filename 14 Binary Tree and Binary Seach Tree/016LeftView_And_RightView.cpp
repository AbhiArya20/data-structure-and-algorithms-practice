#include<bits/stdc++.h>
using namespace std;

// GFG - Left View

class Solution{
    public:
    vector<int> leftView(Node *root){
       if(!root)
            return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int left = -1;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                if(left == -1)
                    left = front->data;
            }
            ans.push_back(left);
        }
        return ans;
    }
};


// GFG - Right View
// LeetCode - 199

class Solution{
    public:
    vector<int> rightView(Node *root){
       if(!root)
            return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int right = -1;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                right = front->data;
            }
            ans.push_back(right);
        }
        return ans;
    }
};