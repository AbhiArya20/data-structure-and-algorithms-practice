#include<bits/stdc++.h>
using namespace std;

// GFG - Top View

class Solution{ // Recursive
    void inorder(Node* root, int horizontal,int vertical, map<int,pair<int,int>> &mp){
        if(!root)
            return;
        if(mp.find(horizontal) == mp.end())
            mp[horizontal] = {vertical,root->data};
        else{
            if(mp[horizontal].first>vertical)
                mp[horizontal] = {vertical,root->data};
        }
        inorder(root->left, horizontal-1,vertical+1, mp);
        inorder(root->right,horizontal+1,vertical+1, mp);
    }
    public:
    vector<int> topView(Node *root){
        map<int, pair<int,int>> mp;
        inorder(root,0,0,mp);
        vector<int> ans;
        for(auto v: mp)
            ans.push_back(v.second.second);
        return ans;
    }
};


class Solution{ // Level-Order
    public:
    vector<int> topView(Node *root){
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto front = q.front().first;
            int hori = q.front().second;
            q.pop();
            if(mp.find(hori)==mp.end())
                mp[hori] = front->data;
            if(front->left)
                q.push({front->left,hori-1});
            if(front->right)
                q.push({front->right,hori+1});
        }
        vector<int> ans;
        for(auto v: mp)
            ans.push_back(v.second);
        return ans;
    }
};