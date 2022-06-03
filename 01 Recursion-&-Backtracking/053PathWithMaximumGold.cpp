#include<bits/stdc++.h>
using namespace std;

// LeetCode = 1219

class Solution {
    int dfs(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0)
            return 0;
        int ans = 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        vector<pair<int,int>> v = {{0,1}, {-1,0}, {1,0}, {0,-1}};
        for(auto c: v){
            ans =max(ans, val + dfs(i+c.first, j+c.second, n, m, grid));
        }
        grid[i][j] = val;
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0)
                    continue;
                int val = dfs(i,j,n,m,grid);
                ans = max(ans, val);
            }
        }
        return ans;
    }
};
