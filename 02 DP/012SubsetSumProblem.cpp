#include<bits/stdc++.h>
using namespace std;

// GFG - Subset Sum Problem

class Solution{   
    int f(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum == 0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int ans = false;
        ans |= f(i-1, sum, arr, dp);
        if(sum>=arr[i])
            ans |= f(i-1,sum-arr[i],arr, dp);
        return dp[i][sum] = ans;
    }
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1, -1));
        int ans = f(n-1,sum,arr,dp);
        return ans;
    }
};

class Solution{    // space optimize
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        int n = arr.size();
        vector<int>dp (sum+1);
        dp[0]=1;
        for(int i = 0; i<n;i++){
            for(int j = sum; j>=arr[i]; j--){
                if(dp[j-arr[i]])
                    dp[j]=1;
            }
        }
        return dp[sum];
    }
};