#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Repeating Subsequence

class Solution { // Memoization - Not Accepted
    int f(int i, int j, int x, int y, string s1, string s2, vector<vector<int>> &dp){
        if(i==x || j==y)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i!=j && s1[i]==s2[j])
            return dp[i][j] = 1+f(i+1, j+1, x, y, s1, s2, dp);
        return dp[i][j] = max(f(i+1, j, x, y, s1, s2, dp), f(i, j+1, x, y, s1, s2, dp));
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    int x = str.size();
		    vector<vector<int>> dp(x,vector<int>(x,-1));
            return f(0,0,x,x,str,str,dp);
		}
};


class Solution { // Tabulation - Accepted
	public:
		int LongestRepeatingSubsequence(string str){
		    int x = str.size();
		    vector<vector<int>> dp(x+1,vector<int>(x+1));
            for(int i = x-1; i>=0; i--){
                for(int j = x-1; j>=0; j--){
                    if(i!=j && str[i]==str[j])
                        dp[i][j] = 1+dp[i+1][j+1];
                    else
                        dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
            return dp[0][0];
		}
};