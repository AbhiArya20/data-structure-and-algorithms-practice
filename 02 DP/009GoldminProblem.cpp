#include<bits/stdc++.h>
using namespace std;

// GFG - Goldmine Proble

class Solution{ // Memoization
    int f(int i, int j,int n,int m, vector<vector<int>> &M, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        int ans = INT_MIN;
        if(dp[i][j]!=-1)
            return dp[i][j];
        ans = max(ans, f(i+1, j+1, n, m, M,dp));
        ans = max(ans, f(i, j+1, n, m, M,dp));
        ans = max(ans, f(i-1, j+1, n, m, M,dp));
        return dp[i][j] = ans + M[i][j];
    }
public:
    int maxGold(int n, int m, vector<vector<int>>& M)
    {
        vector<vector<int>> dp(n,vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, f(i,0,n,m,M,dp));
        }
        return ans;
    }
};


class Solution{ // Tabulation
public:
    int maxGold(int n, int m, vector<vector<int>>& M)
    {
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i = 0; i<n; i++){
            dp[i][m-1] = M[i][m-1];
        }
        for(int j = m-2; j>=0;j--){
            for(int i = 0; i<n; i++){
                int ans = INT_MIN;
                if(i+1<n)
                    ans = max(ans, dp[i+1][j+1]);
                ans = max(ans,dp[i][j+1]);
                if(i-1>=0)
                    ans = max(ans,dp[i-1][j+1]);
                dp[i][j]=ans+M[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans,dp[i][0]);
        }
        return ans;
    }
};



class Solution{ // Space Optimization
public:
    int maxGold(int n, int m, vector<vector<int>>& M)
    {
        vector<int> prev(n);
        for(int i = 0; i<n; i++){
            prev[i]= M[i][m-1];
        }
        for(int j = m-2; j>=0;j--){
            vector<int> cur(n);
            for(int i = 0; i<n; i++){
                int ans = INT_MIN;
                if(i+1<n)
                    ans = max(ans, prev[i+1]);
                ans = max(ans,prev[i]);
                if(i-1>=0)
                    ans = max(ans,prev[i-1]);
                cur[i]=ans+M[i][j];
            }
            prev = cur;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans,prev[i]);
        }
        return ans;
    }
};
