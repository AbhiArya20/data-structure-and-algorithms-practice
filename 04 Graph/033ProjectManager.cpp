#include<bits/stdc++.h>
using namespace std;

// GFG - Project Manager 

class Solution{
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo;
	    vector<int> indegre(V);
	    for(int i = 0; i<V; i++){
	        for(auto c: adj[i])
	            indegre[c]++;
	    }
	    queue<int> q;
	    for(int i = 0; i<V;i++){
	        if(!indegre[i])
	            q.push(i);
	    }
	    while(!q.empty()){
	        int src = q.front();
	        topo.push_back(src);
	        q.pop();
	        for(auto child: adj[src]){
	            indegre[child]--;
	            if(!indegre[child])
	                q.push(child);
	        }
	    }
	    return topo;
	}
	int dfs(int src, vector<int> adj[], vector<bool> &vis,int duration[],vector<int> & dp){
	    if(vis[src])
	        return dp[src];
	    vis[src]=true;
	    int ans = 0;
	    for(auto child: adj[src]){
	        if(!vis[child])
	            ans=max(ans, dfs(child,adj,vis,duration,dp));
	        else 
	            ans = max(ans, dp[child]);
	    }
	    return dp[src] = ans+duration[src];
	}
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        vector<int> adj[n];
        for(auto v: dependency){
            adj[v.first].push_back(v.second);
        }
        auto topo = topoSort(n,adj);
        if(topo.size() != n)
            return -1;
        int ans = 0;
        vector<bool> vis(n);
        vector<int> dp(n);
        for(auto v: topo){
            int nowAns = dfs(v,adj,vis,duration,dp);
            ans = max(ans, nowAns);
        }
        return ans;
    }
};