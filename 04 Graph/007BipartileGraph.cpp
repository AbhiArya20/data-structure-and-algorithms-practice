#include<bits/stdc++.h>
using namespace std;

// LeetCode - 785
// DFS
class Solution {
    bool isBipar(int node,int col, vector<vector<int>>& adj, vector<int> &color){
        color[node] = col;
        for(auto child: adj[node]){
            if(color[child]==-1){
                if(!isBipar(child, !col, adj, color))
                    return false;
            }else if(color[child]==col){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(vector<vector<int>>& adj){
        int V = adj.size();
	    vector<int> color(V,-1);
	    for(int i = 0; i<V; i++){
	        if(color[i]==-1){
	            if(!isBipar(i,0,adj,color))
	                return false;
	        }
	    }
	    return true;
	}
};



// GFG - BFS
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i = 0; i<V; i++){
	        if(color[i]==-1){
	            queue<int> q;
	            q.push(i);
	            color[i]=0;
	            while(!q.empty()){
	                int node = q.front();
	                q.pop();
	                for(auto child: adj[node]){
	                    if(color[child]==-1){
	                        color[child] = !color[node];
	                        q.push(child);
	                    }else if(color[child] == color[node]){
	                        return false;
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
};



// Application
//  	1. Vertex Cover