#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum path sum for each position with jumps under divisibility condition

class Solution{
    vector<int> maxPathSum(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n);
        for(int i = 0; i<n; i++)
            dp[i] = arr[i];
        for(int i = 1; i<n; i++){
            int maxi = 0;
            for(int j = 1; j*j<=i+1; j++){
                if(i+1 != j && (i+1)%j == 0){
                    maxi = max(dp[j-1], maxi);
                    if(j!=1)
                        maxi = max(maxi, dp[(i+1)/j - 1]);
                }
            }
            dp[i] += maxi;
        }
        return dp;
    }
};