#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum Game played by Winner (based on fibonacci)

class Solution{
    int maxGameByWinner(int n){
        vector<int> dp(n);
        if(n == 1)
            return 0;
        dp[0]=1;
        dp[1]=2;
        int i = 1;
        while (dp[i++]<n)
            dp[i] = dp[i-1] + dp[i-2];
        if(dp[i-1] == n)
            return i-1;
        return i-2;        
    }
};