#include<bits/stdc++.h>
using namespace std;


// GFG - Count Binary String

class Solution{
    bool isPowerOf(long val, int base){
        while (val > 1) {
            if (val % base != 0)
                return false;
            val /= base;
        }
        return true;
    }
    int numberOfPartitions(string binaryNo){
        int  n = binaryNo.length();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = ((binaryNo[n - 1] - '0') == 0) ? -1 : 1;
        for (int i = n - 2; i >= 0; i--) {
            if ((binaryNo[i] - '0') == 0) {
                dp[i] = -1;
                continue;
            }
            long val = 0;
            for (int j = i; j < n; j++) {
                val = (val * 2) + (long)(binaryNo[j] - '0');
                if (isPowerOf(val, 5)) {
                    if (j == n - 1)
                        dp[i] = 1;
                    else if (dp[j + 1] != -1)
                            dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
            if (dp[i] == INT_MAX)
                dp[i] = -1;
        }
        return dp[0];
    }
    public:
        int cuts(string s){
            return numberOfPartitions(s);
        } 
};