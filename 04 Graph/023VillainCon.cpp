#include<bits/stdc++.h>
using namespace std;

// GFG - Villain Con

// This is like DP on graph
class Solution{
    int dfs(int src,vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp){
        if(vis[src])
            return dp[src];
        vis[src]=true;
        int ans = 0;
        for(int child: adj[src]){
            if(!vis[child])
                ans = max(ans, 1+dfs(child,adj,vis,dp));
            else{
                ans = max(ans, 1+dp[child]);
            }
        }
        return dp[src]=ans;
    }
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<vector<int>> adj(N);
        for(int i = 0; i<M; i++){
            adj[(mat[i][1]-1)].push_back((mat[i][0]-1));
        }
        int ans=0;
        vector<bool> vis(N);
        vector<int> dp(N);
        for(int i = 0; i<N; i++){
           ans = max(ans,dfs(i,adj,vis,dp));
        }
        return ans+1;
    }
};