#include<bits/stdc++.h>
using namespace std;

// GFG - BBT Counter

class Solution {
    int mod = 1e9+7;
    vector<long long int> dp;
    long long int f(int h){
        if(h==1)
            return h;
        if(h==2)
            return h+1;
        if(dp[h]!=-1)
            return dp[h];
        return dp[h] = (f(h-1)*((2*f(h-2))%mod + f(h-1))%mod)%mod;
    }
  public:
    long long int countBT(int h) { 
       dp.resize(h+1,-1);
       return f(h);
    }
};
