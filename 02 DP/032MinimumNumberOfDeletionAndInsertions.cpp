#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Number of Deletions a insertions

class Solution{
	int f(int i, int j, int x, int y, string s1, string s2, vector<vector<int>> &dp){
        if(i==x || j==y)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1+f(i+1, j+1, x, y, s1, s2, dp);
        return dp[i][j] = max(f(i+1, j, x, y, s1, s2, dp), f(i, j+1, x, y, s1, s2, dp));
    }
	public:
    	int minOperations(string str1, string str2) { 
    	    int x = str1.size();
    	    int y = str2.size();
    	    vector<vector<int>> dp(x,vector<int>(y,-1));
    	    int common = f(0,0,x,y,str1,str2,dp);
    	    int shouldDelete = x - common;
    	    int shouldInsert = y - common;
    	    return shouldDelete + shouldInsert;
    	}
};



