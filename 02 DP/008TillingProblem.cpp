#include<bits/stdc++.h> 
using namespace std;

// GFG - Tilling Problem
// LeetCode - 70

class Solution { // Memoization/Top-Down
    int mod = 1e9+7;
    int f(long long N, vector<int> &dp){
        if(N<=2)
            return N;
        if(dp[N]!=-1)
            return dp[N];
        return dp[N] = (f(N-1,dp)+f(N-2,dp))%mod;
    }
  public:
    long long numberOfWays(long long N) {
        vector<int> dp(N+1, -1);
        return f(N, dp);
    }
};



class Solution { // Tabulation/Buttom-Up
    int mod = 1e9+7;
  public:
    long long numberOfWays(long long n) { 
        long long secondPrev = 1, prev = 2;
        if(n<=2)
            return n;
        for(int i = 3; i<=n; i++){
            int temp = (prev+secondPrev)%mod;
            secondPrev = prev;
            prev = temp;
        }
        return prev%mod;
    }
};
