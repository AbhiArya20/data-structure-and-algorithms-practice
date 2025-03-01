#include<bits/stdc++.h>
using namespace std;

// GFG - Binomial Coefficient
// GFG - Lob Number
// GFG - Number of Unique BST
class Solution{
    int mod = 1e9+7;
    public:
    int nCr(int n, int r,vector<vector<int>>& dp){
        if(r>n)
            return 0;
        if(n==r || r==0)
            return 1;
        if(dp[n][r]!=-1)
            return dp[n][r];
        return dp[n][r] = ((nCr(n-1, r-1,dp)%mod)+(nCr(n-1,r,dp)%mod))%mod;
    }
public:
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
        return nCr(n,r,dp);
    }
};



class Solution{
    int mod = 1e9+7;
    int nCr(int n, int r,vector<vector<int>>& dp){
        if(r>n)
            return 0;
        if(n==r || r==0)
            return 1;
        if(dp[n][r]!=-1)
            return dp[n][r];
        return dp[n][r] = ((r*nCr(n-1, r-1,dp)%mod)+(nCr(n-1,r,dp)%mod))%mod;
    }
public:
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
        return nCr(n,r,dp);
    }
};


class Solution{
    int mod = 1e9+7;
    vector<vector<int>> dp;
public:
    int nCr(int n, int r){
        dp.resize(n+1, vector<int>(r+1, 0));
        for(int i = 0; i<=r; i++)
            dp[i][i] = 1;
        for(int i = 0; i<n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=i; j++){
                dp[i][j] = ((dp[i-1][j-1]%mod)+(dp[i-1][j]%mod))%mod;
            }
        }
    }
    int getAns(int n, int r){
        return dp[n][r];
    }
};







// Permutation Coefficient
class Solution{
    public:
        int permutationCoeff(int n, int k){
            int fact[n + 1];
            fact[0] = 1;
            for(int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1];
            return fact[n] / fact[n - k];
        }
};