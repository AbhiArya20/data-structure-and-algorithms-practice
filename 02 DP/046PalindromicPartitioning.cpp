#include<bits/stdc++.h>
using namespace std;

// LeetCode - 132

class Solution{
    bool isPalindrome(int i,int j,string &s){
        while(i<j)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
    int f(int i,int n, string &str, vector<int> &dp){
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 1e9;
        for(int j = i; j<n; j++){
            if(isPalindrome(i,j,str)){
                ans = min(ans, 1+f(j+1,n,str, dp));
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string str){
        int n = str.size();
        vector<int> dp(n, -1);
        if(isPalindrome(0,n-1,str))
            return 0;
        return f(0,n,str, dp)-1;
    }
};