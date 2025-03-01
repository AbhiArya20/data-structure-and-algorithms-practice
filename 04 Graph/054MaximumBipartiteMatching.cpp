#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum Bipartite Matching

class Solution {
    bool bpm(int src,int n,int m, vector<vector<int>>&G, vector<int> &parent, vector<int> &vis){
        for(int child = 0; child<n; child++){
            if(G[src][child] && !vis[child]){
                vis[child]=true;
                if(parent[child]<0 || bpm(parent[child],n,m,G,parent,vis)){
                    parent[child]=src;
                    return true;
                }
            }
        }
        return false;
    }
public:
	int maximumMatch(vector<vector<int>>&G){
	    int m = G.size();
	    int n = G[0].size();
	    vector<int> parent(n,-1);
	    int ans = 0;
	    for(int i = 0; i<m; i++){
	        vector<int> vis(n);
	        if(bpm(i,n,m,G,parent,vis))
	            ans++;
	    }
	    return ans;
	}

};
