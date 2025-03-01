#include<bits/stdc++.h>
using namespace std;

// GFG - Distinct Occurrences

class Solution{
    int mod = 1e9+7;
    int f(int i, int j, int n, int m, string &s, string &t, vector<vector<int>> &dp){
        if(j==m)
            return 1;
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int untake = f(i+1, j,n,m,s, t, dp);
        int take = 0;
        if(s[i]==t[j])
            take = f(i+1, j+1,n,m, s, t,dp);
        return dp[i][j] =( take + untake )%mod;
    }
    public:
    int subsequenceCount(string S, string T){
        int n = S.size();
        int m = T.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(0,0,n,m,S,T,dp);
    }
};
 