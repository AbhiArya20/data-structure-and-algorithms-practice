#include<bits/stdc++.h>
using namespace std;

// LeetCode - 887
// GFG - Egg Droping


class Solution { // Memoization - Not Accepted at LeetCode but accepted at GFG
    int f(int n, int k,vector<vector<int>> &dp){
        if(n==0)
            return n;
        if(k==1)
            return n;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int ans = 1e9;
        for(int i = 1; i<=n; i++){
            int val = max(f(n-i,k,dp) , f(i-1,k-1,dp));
            ans = min(ans,val);
        }
        return dp[n][k] = 1+ans;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        return f(n,k,dp);
    }
};

class Solution { // Tabulation - Not Accepted at LeetCode
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1));
        for(int i = 1; i<=N; i++){
            dp[i][1] = i;
        }
        for(int n = 1; n<=N; n++){
            for(int k = 2; k<=K; k++){
                int ans = 1e9;
                for(int i = 1; i<=n; i++){
                    int val = max(dp[n-i][k],dp[i-1][k-1]);
                    ans = min(ans,val);
                }
                dp[n][k] = 1+ans;
            }
        }
        return dp[N][K];
    }
};


class Solution { // Accepted
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        int ans = 0;
        while(dp[ans][k]<n){
            ans++;
            for(int i = 1; i<=k; i++){
                dp[ans][i] = 1+dp[ans-1][i-1]+dp[ans-1][i];
            }
        }
        return ans;
    }
};



class Solution { // Optimization of above solution
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k+1);
        int ans = 0;
        while(dp[k]<n){
            for(int i = k; i>0; i--){
                dp[i] += 1+dp[i-1];
            }
            ans++;
        }
        return ans;
    }
};