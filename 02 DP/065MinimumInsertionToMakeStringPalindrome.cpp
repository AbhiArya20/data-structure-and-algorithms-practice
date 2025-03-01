#include<bits/stdc++.h>
using namespace std;

// GFG - Form a palindrome

class Solution{ // Memoization
    int f(int i, int j, int x,string s1, string s2, vector<vector<int>> &dp){
        if(i==x || j==x)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1+f(i+1, j+1, x, s1, s2, dp);
        return dp[i][j] = max(f(i+1, j, x, s1, s2, dp), f(i, j+1, x, s1, s2, dp));
    }
    public:
    int countMin(string s1){
        int x = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(x,vector<int>(x,-1));
        int lcs = f(0,0,x,s1,s2,dp);
        int ans = x - lcs;
        return ans;
    }
};
