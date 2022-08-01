#include<bits/stdc++.h>
using namespace std;

// LeetCode - 516

class Solution {
    int f(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>s.size() || j==0) 
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==s[j-1])
            return dp[i][j] = 1+f(i+1, j-1, s, dp);
        return dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = f(1,n,s,dp);
        return ans;
    }
};


// GFG - Print Longest Palindromic Subsequence
class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++){
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n, j = n;
        while (i > 0 && j > 0){
            if (s[i-1] == t[j-1]){
                ans+=s[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        return ans;
    }
};
