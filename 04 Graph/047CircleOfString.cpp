#include<bits/stdc++.h>
using namespace std;

// GFG - Circle of String

class Solution{ // using directed graph - eular cycle
    void dfs(int src, vector<vector<int>> &adj,vector<bool> &vis){
        vis[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                dfs(child,adj,vis);
            }
        }
    }
    bool kosaRaju(int n, vector<vector<int>> &adj,vector<vector<int>> &adj2){
        vector<bool> vis(n);
        int start = 0;
        for(int i = 0; i<n; i++){
            if(adj[i].size()){
                start = i;
                break;
            }
        }
        dfs(start,adj,vis);
        for(int i = 0; i<n;i++){
            if(adj[i].size() && !vis[i])
                return false;
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
    bool isEularCycle(int n, vector<vector<int>> &adj,vector<vector<int>> &adj2, vector<int> &indegree, vector<int> &outdegree){
        for(int i = 0; i<n; i++){
            if(indegree[i]!=outdegree[i])
                return false;
        }
        bool isTrue = kosaRaju(n,adj,adj2);
        if(!isTrue)
            return false;
        return true;
    }
    public:
    int isCircle(int n, vector<string> a){
        vector<vector<int>> adj(26);
        vector<vector<int>> adj2(26);
        vector<int> indegree(26),outdegree(26);
        for(int i = 0; i<n; i++){
            int u = a[i][0]-'a';
            int v = a[i][a[i].size()-1]-'a';
            adj[u].push_back(v);
            adj2[v].push_back(u);
            outdegree[u]++;
            indegree[v]++;
        }
        return isEularCycle(26,adj,adj2,indegree,outdegree);
    }
};
