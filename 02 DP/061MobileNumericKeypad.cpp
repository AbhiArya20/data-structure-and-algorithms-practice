#include<bits/stdc++.h>
using namespace std;

// GFG - Mobile Numeric keypad

class Solution{
    long long f(int i, int j, int n,vector<vector<int>> &grid, vector<vector<vector<long long>>> &dp){
        if(i<0 || j<0 || i>3 || j>2 || grid[i][j]==-1)
            return 0;
        if(n==1)
            return 1;
        if(dp[n][i][j]!=-1)
            return dp[n][i][j];
        vector<pair<int,int>> v = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
        long long ans = 0;
        for(auto p : v){
            int ni = i+p.first;
            int nj = j+p.second;
            ans += f(ni, nj, n-1, grid,dp);
        }
        return dp[n][i][j] = ans;
    }
	public:
	long long getCount(int n){
	    long long ans = 0;
	    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	    vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(4,vector<long long>(3,-1)));
	    for(int i = 0; i<=3; i++){
	        for(int j = 0; j<=2; j++){
	            if(grid[i][j]!=-1)
    	            ans += f(i,j,n,grid,dp);
	        }
	    }
	    return ans;
	}
};
