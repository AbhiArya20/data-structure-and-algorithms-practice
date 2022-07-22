#include<bits/stdc++.h>
using namespace std;

// LeetCode - 72

class Solution {
    int f(int i, int j, int n, int m, string s, string t, vector<vector<int>> &dp){
        if(j==m)
            return n-i;
        if(i == n)
            return m-j;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i] == t[j])
            return f(i+1, j+1, n, m, s, t, dp);
        int insert = f(i, j+1, n, m, s, t, dp);
        int removed = f(i+1, j, n, m, s, t, dp);
        int replace = f(i+1,j+1,n,m,s,t, dp);
        return dp[i][j] = 1 + min(insert, min(removed,replace));
    }
  public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0,0,n,m,s,t, dp);
    }
};
