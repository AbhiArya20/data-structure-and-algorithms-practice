#include<bits/stdc++.h>
using namespace std;

// GFG - Divisiblity Tree

class Solution {
public:
    int ans = 0;
    int dfs(int i , vector<int> vis, vector<vector<int>> &adj){
        vis[i]= true;
        int res = 0;
        int cnt = 0;
        for(auto u: adj[i]){
            if(!vis[u]){
               res = dfs(u,vis,adj);
               if(res%2==0)
                 ans++;
               else
                  cnt+=res;   
            }
        }
        return cnt+1;    
    }
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
	vector<vector<int>> adj(n);
	vector<int> vis(n, false);
	for(auto i: edges){
	    adj[i[0]-1].push_back(i[1]-1);
	    adj[i[1]-1].push_back(i[0]-1);
	}
	dfs(0,vis,adj);
	return ans;
	}
};