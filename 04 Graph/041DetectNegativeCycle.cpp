#include<bits/stdc++.h>
using namespace std;

// GFG - Detect Negative Cycle

class Solution { // Using Bellman Ford - for connected graph
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,1e8);
	    dist[0]=0;
	    for(int i = 0; i<n-1; i++){
	        for(auto v: edges){
	            if(dist[v[0]]!=1e8 && dist[v[0]]+v[2]<dist[v[1]])
	                dist[v[1]] = dist[v[0]]+v[2];
	        }
	    }
	    for(auto v: edges){
            if(dist[v[0]]+v[2]<dist[v[1]])
                return 1;
        }
        return 0;
	}
};



class Solution {  // // Using Bellman Ford - for disconnected graph
    int isNegativeForConnected(int n,vector<vector<int>>edges,vector<int> &dist){
	    dist.resize(n,1e8);
	    dist[0]=0;
	    for(int i = 0; i<n-1; i++){
	        for(auto v: edges){
	            if(dist[v[0]]!=1e8 && dist[v[0]]+v[2]<dist[v[1]])
	                dist[v[1]] = dist[v[0]]+v[2];
	        }
	    }
	    for(auto v: edges){
            if(dist[v[0]]+v[2]<dist[v[1]])
                return 1;
        }
        return 0;
    }
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<bool> vis(n);
	    vector<int> dist(n,1e8);
	    for(int i = 0;i<n; i++){
	       if(!vis[i]){
	           if(isNegativeForConnected(n,edges,dist))
	                return 1;
	           for(int i = 0;i<n; i++){
	               if(dist[i]!=INT_MAX)
	                    vis[i]=true;
	           }
	       }
	    }
	    return 0;
	}
};




class Solution { // Using Floyd Warshall Algorithms
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
	    for(auto v: edges){
	        dist[v[0]][v[1]] = v[2];
	    }
	    for(int k = 0; k<n; k++){
	        for(int i = 0;i<n;i++){
	            for(int j = 0; j<n; j++){
	                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
	                    dist[i][j]= dist[i][k]+dist[k][j];
	                    if(dist[i][i]<0)
            	            return 1;
	                }
	            }
	        }
	    }
	    return 0;
	}
};