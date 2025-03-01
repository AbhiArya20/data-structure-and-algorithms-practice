#include<bits/stdc++.h>
using namespace std;

// GFG - Eventual Safe State
// LeetCode - 802
class Solution {
    bool dfs(int src,  vector<int> adj[],vector<bool> &check,vector<bool> &stk,vector<bool> &vis){
        vis[src]=stk[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                if(dfs(child, adj, check, stk,vis))
                    return true;
            }
            else if(stk[child])
                return true;
        }
        stk[src]=false;
        check[src]=true;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        vector<bool> stk(V);
        vector<bool> check(V);
        for(int i = 0; i<V; i++){
            if(!vis[i])
                dfs(i,adj,check,stk,vis);
        }
        vector<int> ans;
        for(int i = 0;i<V; i++)
            if(check[i])
                ans.push_back(i);
        return ans;
    }
};