#include<bits/stdc++.h>
using namespace std;

// GFG - Special Keyboard


class Solution{
public:
    long long int optimalKeys(int N){
        if(N<7)
            return N;
        vector<long long int> dp(N+3);
        for(int i = 0; i<7; i++){
            dp[i] = i;
        }
        for(int i = 7; i<=N; i++){
            dp[i] = max(dp[i-3]*2, max(3*dp[i-4], 4*dp[i-5]));
        }
        return dp[N];
    }
};