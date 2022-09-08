#include<bits/stdc++.h>
using namespace std;

class Solution { // Using stack 
    void dfs(int src, vector<int> adj[],vector<bool> &vis,stack<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis,topo);
            }
        }
        topo.push(src);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   stack<int> topo;
	   vector<bool> vis(V);
	   for(int i = 0; i<V; i++){
	       if(!vis[i])
	            dfs(i,adj,vis,topo);
	   }
	   vector<int> ans;
	   while(!topo.empty()){
			ans.push_back(topo.top());
			topo.pop();
	   }
	   return ans;
	}
};



class Solution{ // Using vector or Diparture time
    void dfs(int src, vector<int> adj[],vector<bool> &vis,vector<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis,topo);
            }
        }
        topo.push_back(src);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> topo;
	   vector<bool> vis(V);
	   for(int i = 0; i<V; i++){
	       if(!vis[i])
	            dfs(i,adj,vis,topo);
	   }
	   reverse(topo.begin(),topo.end());
	   return topo;
	}
};



// GFG - Kahn's Algorithms

class Solution
{
	public:
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
};