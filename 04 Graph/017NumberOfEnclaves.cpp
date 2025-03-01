#include<bits/stdc++.h>
using namespace std;

// GFG - Number of Enclaves

class Solution {
    void dfs(int i, int j, int &count, vector<vector<int>> &grid){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || !grid[i][j])
            return;
        count++;
        grid[i][j]=0;
        vector<pair<int,int>> v = {{1,0},{-1,0},{0,-1},{0,1}};
        for(auto p : v){
            dfs(i+p.first, j+p.second, count, grid);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j])
                    count++;
            }
        }
        int count2 = 0;
        for(int i = 0; i<n; i++){
            if(grid[i][0])
                dfs(i,0,count2,grid);
            if(grid[i][m-1])
                dfs(i,m-1,count2,grid);
        }
        for(int i = 0; i<m; i++){
            if(grid[0][i])
                dfs(0,i,count2,grid);
            if(grid[n-1][i])
                dfs(n-1,i,count2,grid);
        }
        return count-count2;
    }
};