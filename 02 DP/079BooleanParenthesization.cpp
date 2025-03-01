#include<bits/stdc++.h>
using namespace std;

// GFG - Boolean Parenthesization

class Solution{
    int mod = 1e3+3;
    long long f(int s, int e,int lookingFor, string &st,vector<vector<vector<int>>> &dp){
        if(s>e)
            return 0;
        if(s==e){
            if(lookingFor)
                return st[s]=='T';
            return st[s]=='F';
        }
        if(dp[s][e][lookingFor]!=-1)
            return dp[s][e][lookingFor];
        long long ans = 0;
        for(int i = s+1; i<e; i+=2){
            long long lt = f(s,i-1,true,st,dp);
            long long lf = f(s,i-1,false,st,dp);
            long long rt = f(i+1,e,true,st,dp);
            long long rf = f(i+1,e,false,st,dp);
            if(st[i]=='&'){
                if(lookingFor){
                    ans += (lt*rt)%mod;
                }else{
                    ans += (((lf*rf)%mod) + ((lf*rt)%mod) + ((lt*rf)%mod))%mod;
                }
            }else if(st[i]=='|'){
                if(lookingFor){
                    ans += (((lt*rt)%mod) + ((lf*rt)%mod) + ((lt*rf)%mod))%mod;
                }else{
                    ans += (lf*rf)%mod;
                }
            }else{
                if(lookingFor){
                    ans += ((lf*rt)%mod) + ((lt*rf)%mod);
                }else{
                    ans += ((lt*rt)%mod) + ((lf*rf)%mod);
                }
            }
            ans %= mod;
        }
        return dp[s][e][lookingFor] = ans;
    }
public:
    int countWays(int n, string &s){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));
        return f(0,n-1,true,s,dp);
    }
};
