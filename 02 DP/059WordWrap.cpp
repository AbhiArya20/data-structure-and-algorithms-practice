#include<bits/stdc++.h>
using namespace std;

// GFG - Word Wrap

class Solution {
    int f(int i,int n, int k, vector<int> &nums,vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int ans = INT_MAX;
        int curLen = 0;
        for(int j = i; j<n; j++){
            int posibleLength = j-i+curLen+nums[j];
            if(posibleLength<=k){
                curLen += nums[j];
                int val = k-posibleLength;
                val*=val;
                if(j==n-1)
                    val = 0;
                int getFurther = val + f(j+1,n,k,nums,dp);
                ans = min(ans,getFurther);
            }else{
                break;
            }
        }
        return dp[i] = ans;
    }
public:
    int solveWordWrap(vector<int>nums, int k) { 
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0,n,k,nums,dp);
    } 
};