#include<bits/stdc++.h>
using namespace std;

// GFG - All Topological Sort 

// Using backtracking
class Solution{
    void backtraing(vector<vector<int>> &adj,vector<int>&ind, vector<int> &vis, vector<int> &temp, vector<vector<int>> &ans){
        bool gone = false;
        int n = adj.size();
        for(int src = 0; src<n; src++){
            if(ind[src]==0 && !vis[src]){
                for(auto child: adj[src]){
                    ind[child]--;
                }
                temp.push_back(src);
                vis[src]=true;
                backtraing(adj,ind,vis,temp,ans);
                temp.pop_back();
                vis[src]=false;
                for(auto child: adj[src]){
                    ind[child]++;
                }
                gone = true;
            }
        }
        if(!gone)
            ans.push_back(temp);
    }
    vector<vector<int>> allTopo(vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> ind(n);
        vector<int> vis(n);
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto childs: adj){
            for(auto child: childs){
                ind[child]++;
            }
        }
        backtraing(adj,ind,vis,temp, ans);
        return ans;
    }
};