#include<bits/stdc++.h>
using namespace std;

// GFG - Biconnected Graph

class Solution{
    bool dfs(int src,int &timer,int parent, vector<int> &dist, vector<int> &low,vector<int> adj[],vector<bool> &vis){
        dist[src]=low[src]=++timer;
        vis[src]=true;
        int children = 0;
        for(auto child: adj[src]){
            if(!vis[child]){
                children++;
                if(dfs(child,timer,src, dist, low, adj,vis))
                    return true;
                low[src] = min(low[src],low[child]);
                if(children>1 && parent==-1)
                    return true;
                if(parent!=-1 && low[child]>=dist[src])
                    return true;
            }else if(child!=parent){
                low[src] = min(low[src],dist[child]);
            }
        }
        return false;
    }
    bool articulationPoints(int n, vector<int> adj[]){
        vector<int> dist(n,0),low(n,0);
        vector<bool> vis(n);
        int timer = 0;
        if(dfs(0,timer,-1,dist,low,adj,vis))
            return false;
        for(int i = 0; i<n; i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
  public:
    int biGraph(int arr[], int n, int e) {
        vector<int> adj[n];
        for(int i = 0; i<2*e; i+=2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        return articulationPoints(n,adj);
    }
};