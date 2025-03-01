#include<bits/stdc++.h>
using namespace std;

// GFG - Bridge

class Solution{
    void dfs(int src,int &timer,int parent, vector<int> &dist, vector<int> &low,vector<int> adj[],vector<bool> &vis,vector<pair<int,int>> &ans){
        dist[src]=low[src]=++timer;
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,timer,src, dist, low, adj,vis,ans);
                low[src] = min(low[src],low[child]);
                if(low[child]>dist[src])
                    ans.push_back({src,child});
            }else if(child!=parent){
                low[src] = min(low[src],dist[child]);
            }
        }
    }
	public:
    vector<pair<int,int>> articulationPoints(int n, vector<int> adj[]){
        vector<int> dist(n,0),low(n,0);
        vector<bool> vis(n);
        vector<pair<int,int>> ans;
        int timer = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i])
                dfs(i,timer,-1,dist,low,adj,vis,ans);
        }
        return ans;
    }
};