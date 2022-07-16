#include<bits/stdc++.h>
using namespace std;

// LeetCode - 931

class Solution { 
    int f(int i, int j, int n,vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(j<0 || j>=n)
            return INT_MAX;
        if(i==n-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = f(i+1, j+1, n, grid, dp);
        int left = f(i+1, j-1, n, grid, dp);
        int down = f(i+1, j, n, grid, dp);
        return dp[i][j] = grid[i][j] + min(down,min(left,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n, -1));
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            int val = f(0, i, n, matrix,dp);
            ans = min(ans, val);
        }
        return ans;
    }
};