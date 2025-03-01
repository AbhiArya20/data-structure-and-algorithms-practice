#include<bits/stdc++.h>
using namespace std;

// LeetCode - 987

class Solution {
    map<int, map<int,multiset<int>>> mp;
    void preOrder(TreeNode* root,int h,int d){
        if(!root)
            return;
        mp[h][d].insert(root->val);
        preOrder(root->left,h-1,d+1);
        preOrder(root->right,h+1,d+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preOrder(root,0,0);
        vector<vector<int>> ans;
        for(auto dep: mp){
            vector<int> temp;
            for(auto st : dep.second){
                for(auto v: st.second){
                    temp.push_back(v);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// GFG - Vertical Traversal Of Binary Tree
class Solution {
    map<int, map<int,vector<int>>> mp;
    void preOrder(Node* root,int h,int d){
        if(!root)
            return;
        mp[h][d].push_back(root->data);
        preOrder(root->left,h-1,d+1);
        preOrder(root->right,h+1,d+1);
    }
public:
    vector<int> verticalOrder(Node *root){
        preOrder(root,0,0);
        vector<int> ans;
        for(auto dep: mp){
            for(auto st : dep.second){
                for(auto v: st.second){
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};