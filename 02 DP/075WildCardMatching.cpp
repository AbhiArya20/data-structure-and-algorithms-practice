#include<bits/stdc++.h>
using namespace std;

// LeetCode - 44

class Solution {
    vector<vector<int>> dp;
    int f(int i, int j, string &s, string &p){
        if(i==s.size()){
            for(int k = j; k<p.size(); k++){
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
        if(j==p.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = false;
        if(s[i]==p[j] || p[j]=='?')
            ans = ans || f(i+1,j+1,s,p);
        if(p[j]=='*')
            ans = ans || f(i,j+1,s,p)||f(i+1,j+1,s,p)||f(i+1,j,s,p);
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string &s, string &p) {
        dp.resize(s.size(), vector<int>(p.size(), -1));
        return f(0,0,s,p);
    }
};