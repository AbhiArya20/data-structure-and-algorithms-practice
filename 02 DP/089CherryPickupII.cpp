#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1463

class Solution {
    vector<vector<vector<int>>> dp;
    int f(int i, int j, int k,int n, int m, vector<vector<int>> &grid){
        if(i>=n)
            return 0;
        if(j<0 || k<0 || j>=m || k>=m)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        int ans = -1e9;
        for(int r = -1; r<=1; r++){
            for(int c = -1; c<=1;c++){
                if(j==k)
                    ans = max(ans, grid[i][j] + f(i+1,j+r,k+c,n,m,grid));
                else 
                    ans = max(ans, grid[i][j] + grid[i][k] + f(i+1,j+r,k+c,n,m,grid));
            }
        }
        return dp[i][j][k]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,n,m,grid);
    } 
};