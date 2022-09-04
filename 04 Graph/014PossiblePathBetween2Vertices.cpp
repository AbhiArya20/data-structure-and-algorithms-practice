#include<bits/stdc++.h>
using namespace std;

// GFG - Possible paths between 2 vertices

class Solution {
    int mod = 1e9+7;
    int dfs(int u,int v,vector<int>adj[],vector<bool>& vis){
        if(u==v) return 1;
        vis[u]=true;
        int ans = 0;
        for(auto i: adj[u]){
            if(!vis[i]){
                ans+=dfs(i,v,adj,vis);
                ans%=mod;
            }
        }
        vis[u]=false;
        return ans;
    }
  public:
	int countPaths(int V, vector<int> adj[], int s, int v) {
	    vector<bool> vis(V);
	    return dfs(s,v,adj,vis);
	}

};


// Possible Paths
class Solution {
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int dfs(int u,int v,int k,vector<vector<int>>&graph){
        if(k==0)
            return u==v;
        int ans = 0;
        if(dp[u][k]!=-1)
            return dp[u][k];
        for(int i = 0; i<graph.size(); i++){
            if(graph[u][i]){
                ans+=dfs(i,v,k-1,graph);
                ans%=mod;
            }
        }
        return dp[u][k] = ans;
    }
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    int n = graph.size();
	    dp.resize(n,vector<int>(k+1, -1));
	    return dfs(u,v,k,graph);
	}
};