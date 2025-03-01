#include<bits/stdc++.h>
using namespace std;

// GFG - Sum of All Substring of a number


class Solution
{
    int mod = 1e9+7;
    public:
        long long sumSubstrings(string s){
        int n = s.size();
        long long  prev = s[0]-'0';
        long long  ans = prev;
        for(int i = 1; i<n;i++){
            int val = s[i] -'0';
            prev = ((i + 1)*val)%mod + (10*prev)%mod;
            ans+=prev;
            ans%=mod;
        }
        return ans;
        }
};