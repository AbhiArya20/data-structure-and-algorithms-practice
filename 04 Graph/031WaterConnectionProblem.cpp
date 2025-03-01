#include<bits/stdc++.h>
using namespace std;

// GFG - Water Connection Problem

class Solution{
    void dfs(int src , int &last, int &mini, vector<vector<pair<int,int>>> &adj,vector<bool> &vis){
        vis[src]=true;
        last = src;
        for(auto childPair: adj[src]){
            if(!vis[childPair.first]){
                mini = min(mini, childPair.second);
                dfs(childPair.first,last,mini, adj,vis);
            }
        }
        
    }
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
        vector<vector<int>> ans;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegre(n);
        for(int i = 0; i<p; i++){
            adj[a[i]-1].push_back({b[i]-1, d[i]});
            indegre[b[i]-1]++;
        }
        
        vector<bool> vis(n);
        int count = 0;
        sort(a.begin(),a.end());
        for(auto i: a){
            i = i-1;
            if(indegre[i] == 0 && !vis[i]){
                count++;
                int start = i;
                int last = i;
                int mini = INT_MAX;
                dfs(i,last,mini,adj,vis);
                ans.push_back({start+1,last+1,mini});
            }
        }
        return ans;
    }
};