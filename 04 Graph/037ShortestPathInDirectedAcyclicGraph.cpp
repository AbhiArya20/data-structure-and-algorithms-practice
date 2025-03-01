#include<bits/stdc++.h>
using namespace std;

// GFG - Shortest path in Directed Acyclic Graph

class Solution {
    void dfs(int src, vector<vector<pair<int,int>>> &adj,vector<bool> &vis,stack<int> &topo){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child.first]){
                dfs(child.first,adj,vis,topo);
            }
        }
        topo.push(src);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        for(auto v: edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<bool> vis(N);
        stack<int> topo;
        dfs(0,adj,vis,topo);
        vector<int> dist(N,INT_MAX);
        dist[topo.top()] = 0;
        while(!topo.empty()){
            int src = topo.top();
            topo.pop();
            for(auto childPair: adj[src]){
                if(dist[src]+childPair.second < dist[childPair.first]){
                    dist[childPair.first]=dist[src]+childPair.second;
                }
            }
        }
        for(auto &i : dist){
            if(i == INT_MAX)
                i = -1;
        }
        return dist;
    }
};