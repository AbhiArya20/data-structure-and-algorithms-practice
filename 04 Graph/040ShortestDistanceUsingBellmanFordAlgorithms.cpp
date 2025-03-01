#include<bits/stdc++.h>
using namespace std;

// GFG - Distance from Source (Bellman Ford Algorithm)

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
	    dist[S]=0;
	    for(int i = 0; i<V-1; i++){
	        for(auto v: edges){
	            if(dist[v[0]]!=1e8 && dist[v[0]]+v[2]<dist[v[1]])
	                dist[v[1]] = dist[v[0]]+v[2];
	        }
	    }
	    for(auto v: edges){
            if(dist[v[0]]+v[2]<dist[v[1]])
                return {-1};
        }
        return dist;
    }
};