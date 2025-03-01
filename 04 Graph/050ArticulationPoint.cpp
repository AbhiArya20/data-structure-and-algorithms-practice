#include<bits/stdc++.h>
using namespace std;

// GFG - Articulation Point

class Solution{
    void dfs(int src,int &timer,int parent, vector<int> &dist, vector<int> &low,vector<int> adj[],vector<bool> &vis,unordered_set<int> &ans){
        dist[src]=low[src]=++timer;
        vis[src]=true;
        int children = 0;
        for(auto child: adj[src]){
            if(!vis[child]){
                children++;
                dfs(child,timer,src, dist, low, adj,vis,ans);
                low[src] = min(low[src],low[child]);
                if(parent!=-1 && low[child]>=dist[src])
                    ans.insert(src);
            }else if(child!=parent){
                low[src] = min(low[src],dist[child]);
            }
        }
        if(children>1 && parent==-1)
            ans.insert(src);
    }
	public:
    vector<int> articulationPoints(int n, vector<int> adj[]){
        vector<int> dist(n,0),low(n,0);
        vector<bool> vis(n);
        vector<int> ans;
        unordered_set<int> temp;
        int timer = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i])
                dfs(i,timer,-1,dist,low,adj,vis,temp);
        }
        if(temp.size()==0)
            ans.push_back(-1);
        ans.insert(ans.begin(), temp.begin(), temp.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};
