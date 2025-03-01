#include<bits/stdc++.h>
using namespace std;

// GFG - Interleaving String
class Solution{
    int f(int i, int j, int k,int n,int m, int o, string &a, string &b, string &c,vector<vector<int>> &dp){
        if(k == o)
            return true;
        if(i==n){
            for(int g = j; g<m;g++){
                if(c[k]==b[g])
                    k++;
                if(k==o)
                    return true;
            }
            return false;
        }
        if(j==m){
            for(int g = i; g<n;g++){
                if(c[k]==a[g])
                    k++;
                if(k==o)
                    return true;
            }
            return false;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = false;
        if(a[i]==c[k])
            ans |= f(i+1,j,k+1,n,m,o,a,b,c,dp);
        if(b[j]==c[k])
            ans |= f(i,j+1,k+1,n,m,o,a,b,c,dp);
        return dp[i][j] = ans;
    }
  public:
    bool isInterleave(string &A, string &B, string &C) {
        int n = A.size();
        int m = B.size();
        int o = C.size();
        if(o!=m+n)
            return false;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,0,n,m,o,A,B,C,dp);
    }
};
