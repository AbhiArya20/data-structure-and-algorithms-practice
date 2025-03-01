#include<bits/stdc++.h>
using namespace std;

// GFG - Unit Area of largest region of 1's

class Solution
{
    void dfs(int i, int j, vector<vector<int>> &grid, int &tempAns){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| !grid[i][j])
            return;
        grid[i][j]=0;
        tempAns++;
        vector<pair<int,int>> v = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        for(auto c: v){
            dfs(i+c.first, j+c.second, grid, tempAns);
        }
    }
    public:
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    int tempAns = 0;
                    dfs(i,j,grid,tempAns);
                    ans = max(ans, tempAns);
                }
            }
        }
        return ans;
    }
};