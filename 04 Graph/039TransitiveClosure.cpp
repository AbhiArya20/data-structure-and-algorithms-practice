#include<bits/stdc++.h>
using namespace std;

// GFG - Transitive Closure

class Solution{ // Using Floyed Warshall 
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> matrix)
    {
        int n = matrix.size();
        for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(matrix[i][j]==0){
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
	            if(i==j){
	               matrix[i][j]=1;
	            }
	            else if(matrix[i][j]==INT_MAX){
	                matrix[i][j]=0;
	            }else{
	                matrix[i][j]=1;
	            }
	        }
	    }
        return matrix;
    }
};


class Solution{ // DFS
    void dfs(int src, int start, vector<vector<int>> &graph,vector<bool> &vis,vector<vector<int>> &ans){
        vis[src]=true;
        ans[start][src]=1;
        for(int i = 0; i<graph.size();i++){
            if(graph[src][i] && !vis[i]){
                dfs(i,start, graph, vis,ans);
            }
        }
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph){
        vector<vector<int>> ans(N, vector<int> (N));
        for(int i = 0; i<graph.size(); i++){
            vector<bool> vis(N);
            dfs(i,i,graph,vis,ans);
        }
        return ans;
    }
};
