#include<bits/stdc++.h>
using namespace std;

// GFG - Strongly Connected Components

class Solution{
    void dfs(int src, vector<int> adj[],vector<bool> &vis,stack<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis,topo);
            }
        }
        topo.push(src);
    }
    void dfs(int src, vector<int> adj[],vector<bool> &vis){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis);
            }
        }
    }
	public:
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> topo;
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i])
                dfs(i,adj,vis,topo);
        }
        vector<int> adj2[V];
        for(int i = 0; i<V;i++){
            for(int child: adj[i]){
                adj2[child].push_back(i);
            }
        }
        vis.clear();
        vis.resize(V);
        int ans = 0;
        while(!topo.empty()){
            if(!vis[topo.top()]){
                dfs(topo.top(), adj2,vis);
                ans++;
            }
            topo.pop();
            
        }
        return ans;
    }
};
