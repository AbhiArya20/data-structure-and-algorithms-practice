#include<bits/stdc++.h>
using namespace std;

// GFG - Adjacents Are Not Allowed

class Solution{
    int f(int i, int n, vector<vector<int>> &mat, vector<int> &dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int untake = f(i+1, n, mat, dp);
        int take = max(mat[0][i],mat[1][i]) + f(i+2, n, mat, dp);
        return dp[i] = max(take, untake);
    }
public:
    int maxSum(int N, vector<vector<int>> &mat){
        vector<int> dp(N, -1);
        return f(0,N,mat,dp);
    }
};