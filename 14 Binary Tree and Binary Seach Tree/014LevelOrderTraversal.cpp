#include<bits/stdc++.h>
using namespace std;

// LeetCode - 102

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// LeetCode - 103


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        int leftToRight = true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp.push_back(front->val);
            }
            if(!leftToRight){
                reverse(temp.begin(), temp.end());
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};


// LeetCode - 107

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// LeetCode - 429

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                for(auto child: front->children)
                    q.push(child);
                temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// LeetCode - 1161

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int level = 1;
        int maxi = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            int sum = 0;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                sum += front->val;
            }
            if(maxi<sum){
                ans = level;
                maxi = sum;
            }
            level++;
        }
        return ans;
    }
};


// GFG - Connect Nodes at Same Level

class Solution{
    public:
    void connect(Node *root){
        int leftToRight = true;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*> temp;
            while(size--){
                auto front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp.push_back(front);
            }
            for(int i = 0; i<temp.size()-1; i++){
                temp[i]->nextRight = temp[i+1];
            }
        }
    }    
};
