#include<bits/stdc++.h>
using namespace std;

// GFG - Buttom View

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty()){
            Node* front = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(front->left)
                q.push({front->left,dist-1});
            if(front->right)
                q.push({front->right,dist+1});
            mp[dist] = front->data;
        }
        vector<int> ans;
        for(auto v: mp)
            ans.push_back(v.second);
        return ans;
    }
};