#include<bits/stdc++.h>
using namespace std;

// GFG - Euler circuit and Path - undirected graph
// Euler Path - zero or two vertex have odd indegree and  each vertex has even or zero indegree
// Eular cycle - each vertex has even or zero indegree
class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
	    vector<int> indegre(V);
	    for(int i = 0; i<V; i++){
	        for(auto child: adj[i]){
	            indegre[child]++;
	        }
	    }
	    bool isCycle = true;
	    int count = 0;
	    for(auto c: indegre){
	        if(c&1){
	            isCycle = false;
	            count++;
	        }
	    }
	    if(isCycle)
	        return 2;
	    return count == 0 || count == 2;
	}
};



// GFG - Euler circuit and Path - directed graph
// Eular cycle - indegree == outdegree for every vertex and very nonzero degree vertex should belong to SCC
class Solution{
    void dfs(int src, vector<vector<int>>&adj,vector<bool> &vis,stack<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis,topo);
            }
        }
        topo.push(src);
    }
    void dfs(int src, vector<vector<int>> &adj,vector<bool> &vis){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis);
            }
        }
    }
    bool kosaRaju(int n, vector<vector<int>> &adj){
        stack<int> topo;
        vector<bool> vis(n);
        int start = 0;
        for(int i = 0; i<n; i++){
            if(adj[i].size()){
                start = i;
                break;
            }
        }
        dfs(start,adj,vis,topo);
        for(int i = 0; i<n;i++){
            if(adj[i].size() && !vis[i])
                return false;
        }
        vector<vector<int>> adj2(n);
        for(int i = 0; i<n;i++){
            for(int child: adj[i]){
                adj2[child].push_back(i);
            }
        }
        vis.clear();
        vis.resize(n);
        dfs(start, adj2,vis);
        for(int i = 0; i<n;i++){
            if(adj[i].size() && !vis[i])
                return false;
        }
        return true;
    }
	public:
    bool isEularCycle(int n, vector<vector<int>> &adj){
        bool isTrue = kosaRaju(n,adj);
        if(!isTrue)
            return false;
        vector<int> indegree(n),outdegree(n);
        for(int i = 0; i<n; i++){
            outdegree[i]=adj[i].size();
            for(auto v: adj[i]){
                indegree[v]++;
            }
        }
        for(int i = 0; i<n; i++){
            if(indegree[i]!=outdegree[i])
                return false;
        }
        return true;
    }
};
