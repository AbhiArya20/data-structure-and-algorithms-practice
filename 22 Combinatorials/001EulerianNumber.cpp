#include<bits/stdc++.h>
using namespace std;

// GFG - Eulerian Number

class Solution{
    int f(int n, int m,vector<vector<int>> &dp){
        if(m>=n || n==0)
            return 0;
        if(m==0)
            return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        return dp[n][m] = (n-m)*f(n-1,m-1,dp)+(m+1)*f(n-1,m,dp);
    }
    public:
        int EulerianNumber(int n, int m){
            vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
            return f(n,m,dp);
        }
};