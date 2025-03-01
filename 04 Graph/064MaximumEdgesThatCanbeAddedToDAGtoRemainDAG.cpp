#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum Edges Added and DAG is still DAG

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
    int count(int n,vector<int> adj[]){
        auto topo = topoSort(n,adj);
        vector<int> vis(n);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int src = topo[i];
            for(auto child: adj[src]){
                vis[child]=true;
            }
            for(int j = i+1; j<n; j++){
                if(!vis[j]){
                    ans++;
                    cout<<src<<" "<<topo[j]<<endl; // to print edges
                }
                vis[topo[j]]=false;
            }
        }
        return ans;
    }
};