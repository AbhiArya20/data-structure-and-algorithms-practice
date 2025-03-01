#include<bits/stdc++.h>
using namespace std;

// GFG - Dice Throw
// LeetCode - 1155

class Solution {
    long long f(int n, int x, int m, vector<vector<long long>> &dp){
        if(n==0){
            return x == 0;
        }
        if(dp[n][x]!=-1)
            return dp[n][x];
        long long ans = 0;
        for(int i = 1; i<=m; i++){
            if(i<=x){
                ans += f(n-1, x-i, m, dp);
            }
        }
        return dp[n][x] = ans;
    }
  public:
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1, -1));
        return f(N,X,M,dp);
    }
};
