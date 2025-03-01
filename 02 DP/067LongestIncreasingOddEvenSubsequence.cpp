#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Increasing Odd Even Subsequence

class Solution{ // Tabulation
    public:
    int longestSubsequence(int n, int a[]){
       int ans = 1;
       vector<int> dp(n,1);
       for(int i = 1; i<n; i++){
           for(int j = 0; j<i; j++){
               if(a[i]>a[j] && (a[i] + a[j]) % 2 != 0 && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
           }
           ans = max(ans, dp[i]);
       }
       return ans;
    }
};