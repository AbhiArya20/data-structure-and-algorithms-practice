#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Common Substring

class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m){
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 || j==0){
                    if(s1[i] == s2[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }else{
                    if(s1[i] == s2[j])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
