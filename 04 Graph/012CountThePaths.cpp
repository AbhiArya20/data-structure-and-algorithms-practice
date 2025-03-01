#include<bits/stdc++.h>
using namespace std;

// GFG - Count The Paths

class Solution {
    int dfs(int s, int d, vector<vector<int>> &adj,vector<bool> &vis){
        if(s==d)
            return 1;
        vis[s]=true;
        int ans = 0;
        for(auto child: adj[s])
            if(!vis[child])
                ans += dfs(child,d,adj,vis);
        vis[s]=false;
        return ans;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<vector<int>> adj(n);
	    vector<bool> vis(n);
	    for(auto v: edges)
	        adj[v[0]].push_back(v[1]);
	    return dfs(s,d,adj,vis);
	}
};