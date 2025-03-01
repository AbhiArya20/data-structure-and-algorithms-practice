#include<bits/stdc++.h>
using namespace std;

// LeetCode - 10

class Solution {
    vector<vector<int>> dp;
    int f(int i, int j, string &s, string &p){
        if(i>=s.size() && j>=p.size()){
            return true;
        }
        if(j>=p.size())
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        if(j+1<p.size() && p[j+1]=='*'){
            int ans = false;
            ans =  ans || f(i,j+2,s,p);
            if(match)
                ans = ans || f(i+1, j, s, p);
            return dp[i][j] = ans;
        }
        if(match)
           return dp[i][j] = f(i+1,j+1,s,p);
        return dp[i][j] = false;
    }
public:
    bool isMatch(string &s, string &p) {
        dp.resize(s.size()+1, vector<int>(p.size()+1, -1));
        return f(0,0,s,p);
    }
};