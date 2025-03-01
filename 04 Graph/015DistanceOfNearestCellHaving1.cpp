#include<bits/stdc++.h>
using namespace std;

// GFG - Distance of nearest cell having 1

class Solution {
    public:
    vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>,int>> q;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	            }
	        }
	    }
	    vector<vector<int>> ans(n,vector<int>(m));
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        ans[r][c]=d;
	        vector<pair<int,int>> v = {{1,0},{-1,0},{0,1},{0,-1}};
	        for(auto p: v){
	            int nr = r+p.first;
	            int nc = c+p.second;
	            if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc])
	                continue;
	            grid[nr][nc]=1;
	            q.push({{nr, nc},d+1});
	        }
	    }
	    return ans;
	}
};