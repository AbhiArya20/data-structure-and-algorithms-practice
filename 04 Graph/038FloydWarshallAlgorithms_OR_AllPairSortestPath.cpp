#include<bits/stdc++.h>
using namespace std;

// GFG - Floyd Warshall Algorithm
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=INT_MAX;
	            }
	        }
	    }
	    for(int k = 0; k<n; k++){
	        for(int i = 0; i<n; i++){
    	        for(int j = 0; j<n; j++){
    	            if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX && matrix[i][j]>matrix[i][k]+matrix[k][j]){
    	                matrix[i][j]=matrix[i][k]+matrix[k][j];
    	            }
    	        }
    	    }
	    }
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(matrix[i][j]==INT_MAX){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};



// All Pair Shortest Path using Dijkstra Algorithm - more efficient than floyd Warshall Algorithm
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    vector<vector<pair<int,int>>> adj(n);
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(i!=j && matrix[i][j]!=-1){
	               adj[i].push_back({j,matrix[i][j]});
	            }
	        }
	    }
	    vector<vector<int>> ans;
	    for(int i = 0; i<n; i++){
	        vector<int> dist(n,INT_MAX);
	        dist[i]=0;
	        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	        pq.push({0,i});
	        while(!pq.empty()){
	            int src = pq.top().second;
	            pq.pop();
	            for(auto childPair: adj[src]){
	                int child = childPair.first;
	                int wt = childPair.second;
	                if(dist[child]>dist[src]+wt){
	                    dist[child]=dist[src]+wt;
	                    pq.push({dist[child],child});
	                }
	            }
	        }
	        ans.push_back(dist);
	    }
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(ans[i][j]==INT_MAX)
	                ans[i][j] = -1;
	        }
	    }
	    matrix = ans;
	}
};