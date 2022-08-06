#include<bits/stdc++.h>
using namespace std;

// LeetCode - 91
class Solution {
    int f(int i,int n, string s, vector<int> &dp){
        if(i == n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 0;
        ans += f(i+1,n,s,dp);
        if(i+1<n && ((s[i]=='1' && s[i+1]>='0' && s[i+1]<='9')  ||  (s[i]<='2' && s[i+1]>='0' && s[i+1]<='6')))
            ans += f(i+2,n,s,dp);
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp);
    }
};

// LeetCode - 639
class Solution {
    int mod = 1e9+7;
    long long f(int i,int n, string &s, vector<int> &dp){
        if(i == n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long ans = 0;
        if(s[i]=='*'){
            ans += 9*f(i+1,n,s,dp);
            ans %= mod;
        }
        else{
            ans += f(i+1, n, s, dp);
            ans %= mod;
        }        
        if(i+1<n){
            if(s[i] == '*' && s[i+1] == '*'){
                ans += 15*f(i+2,n,s,dp);
                ans %= mod;
            }else if(s[i] == '1' && s[i+1] == '*'){
                ans += 9 * f(i+2,n,s,dp);
                ans %= mod;
            }else if(s[i]=='2' && s[i+1]=='*'){
                ans += 6*f(i+2,n,s,dp);
                ans %= mod;
            }else if(s[i]=='*'){
                if(s[i+1]>='0' && s[i+1]<='6'){
                    ans += 2*f(i+2,n,s,dp);
                    ans %= mod;
                }else if(s[i+1]>='7' && s[i+1]<='9'){
                    ans += f(i+2,n,s,dp);
                    ans %= mod;
                }
            }else if(((s[i]=='1' && s[i+1]>='0' && s[i+1]<='9')  ||  (s[i]<='2' && s[i+1]>='0' && s[i+1]<='6'))){
                ans += f(i+2,n,s,dp);
                ans %= mod;
            }
            ans %= mod;
        }
        return dp[i] = (int)ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp);
    }
};