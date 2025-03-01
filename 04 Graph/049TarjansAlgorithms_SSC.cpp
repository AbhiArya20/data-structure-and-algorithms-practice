#include<bits/stdc++.h>
using namespace std;

// GFG - Tarjan's Algo -SSC

class Solution{
    void dfs(int src,int &time, vector<int> &dist, vector<int> &low,vector<int> adj[],vector<bool> &vis,stack<int> &temp,vector<vector<int>> &ans){
        dist[src]=low[src]=++time;
        vis[src]=true;
        temp.push(src);
        for(auto child: adj[src]){
            if(dist[child]==-1){
                dfs(child,time, dist, low, adj,vis,temp,ans);
                low[src] = min(low[src],low[child]);
            }else if(vis[child]){
                low[src] = min(low[src],dist[child]);
            }
        }
        if(low[src]==dist[src]){
            vector<int> tempAns;
            while(temp.top() != src){
                vis[temp.top()]=false;
                tempAns.push_back(temp.top());
                temp.pop();
            }
            vis[temp.top()]=false;
            tempAns.push_back(temp.top());
            temp.pop();
            sort(tempAns.begin(), tempAns.end()); // sorting is just to pass test-cases
            ans.push_back(tempAns);
        }
    }
	public:
    vector<vector<int>> tarjans(int n, vector<int> adj[]){
        vector<int> dist(n,-1),low(n,-1);
        vector<bool> vis(n);
        stack<int> temp;
        vector<vector<int>> ans;
        int time = 0;
        for(int i = 0; i<n; i++){
            if(dist[i]==-1)
                dfs(i,time,dist,low,adj,vis,temp,ans);
        }
        sort(ans.begin(), ans.end()); // sorting is just to pass test-cases
        return ans;
    }
};