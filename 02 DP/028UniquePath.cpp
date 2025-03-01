#include<bits/stdc++.h>
using namespace std;

// LeetCode - 62

class Solution {
    int f(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        if(i==n-1 && j == m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = f(i, j+1, n, m, dp);
        int down = f(i+1, j, n, m, dp);
        return dp[i][j] = down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return f(0,0,m,n,dp);
    }
};


// LeetCode - 63

class Solution {
    int f(int i, int j, int n, int m,vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j])
            return 0;
        if(i==n-1 && j == m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = f(i, j+1, n, m,grid, dp);
        int down = f(i+1, j, n, m,grid, dp);
        return dp[i][j] = down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m, -1));
        return f(0,0,n,m,grid,dp);
    }
};