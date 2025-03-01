#include<bits/stdc++.h>
using namespace std;

// GFG - Mother Vertex

class Solution 
{
    void dfs(int src, vector<int> adj[],vector<bool> &vis,vector<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis,topo);
            }
        }
        topo.push_back(src);
    }
	void dfs(int node,int &count, vector<int> adj[],vector<bool> &vis){
        vis[node] = true;
        count++;
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(child,count, adj, vis);
            }
        }
    }
    public:
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V);
	    vector<int> topo;
	    for(int i = 0; i<V; i++){
	        if(!vis[i])
	            dfs(i,adj,vis,topo);
	    }
	    reverse(topo.begin(),topo.end());
	    int count = 0;
	    vis.clear();
	    vis.resize(V);
	    dfs(topo[0],count,adj,vis);
	    if(count == V)
	        return topo[0];
	    return -1;
	}
};