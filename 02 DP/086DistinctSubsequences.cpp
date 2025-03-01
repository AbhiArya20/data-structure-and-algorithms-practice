#include<bits/stdc++.h>
using namespace std;

// LeetCode - 115

class Solution {
    vector<vector<int>> dp;
    int f(int i, int j, string &s, string &t){
        if(j==t.size())
            return 1;
        if(i==s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = f(i+1,j,s,t);
        if(s[i]==t[j]){
            ans+=f(i+1,j+1,s,t) ;
        }
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string &s, string &t) {
        dp.resize(s.size(), vector<int>(t.size(),-1));
        return f(0,0,s,t);
    }
};