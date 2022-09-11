#include<bits/stdc++.h>
using namespace std;

// GFG - Party in Town

class Solution{
    int dfs(int src, vector<vector<int>> &adj, vector<bool> &vis){
        vis[src]=true;
        int ans = 0;
        for(auto child: adj[src]){
            if(!vis[child])
                ans = max(ans,dfs(child,adj,vis));
        }
        return ans+1;
    }
public:
    int partyHouse(int n, vector<vector<int>> &adj){
        int ans = n+1;
        for(int i = 1; i<=n;i++){
            vector<bool> vis(n+1);
            int depth = dfs(i,adj,vis);
            ans = min(ans, depth);
        }
        return ans-1;
    }
};