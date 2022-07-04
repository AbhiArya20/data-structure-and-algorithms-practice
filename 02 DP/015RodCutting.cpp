#include<bits/stdc++.h>
using namespace std;

// GFG - Rod Cutting

class Solution{
    int f(int i, int n, int price[], vector<vector<int>> &dp){
        if(n == 0)
            return 0;
        if(i<0)
            return -1e9;
        if(dp[i][n]!=-1)
            return dp[i][n];
        int ans = -1e9;
        ans = max(ans,f(i-1, n, price, dp));
        if(n>=i+1)
            ans = max(ans,price[i]+f(i,n-i-1,price, dp));
        return dp[i][n] = ans;
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1, -1));
        int ans = f(n-1,n,price,dp);
        return ans;
    }
};




// GFG - Minimum cost to fill given weight in a bag

class Solution{
    int f(int i, int cost[], int n, int w,vector<vector<int>> &dp){
        if(w==0)
            return 0;
        if(i == n)
            return 1e9;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int untake = f(i+1,cost,n,w,dp);
        int take = 1e9;
        if(cost[i]!=-1 && w>=i+1){
            take =  cost[i] + f(i,cost,n,w-i-1, dp);
        }
        return dp[i][w] = min(untake, take);
    }
	public:
	int minimumCost(int cost[], int N, int W) 
	{
        vector<vector<int>> dp(N,vector<int>(W+1, -1));
        int ans =  f(0, cost, N, W, dp);
        if(ans == 1e9)
            return -1;
        return ans;
	} 
};