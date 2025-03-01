#include<bits/stdc++.h>
using namespace std;


// GFG - Perfect Sum Problem

class Solution{
    int mod = 1e9+7;
    int f(int i, int sum, int arr[], vector<vector<int>> &dp){
        if(i<0)
            return sum == 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
       long long untake = f(i-1, sum, arr, dp);
       untake %= mod;
       int take = 0;
       if(sum>=arr[i])
            take = f(i-1,sum-arr[i],arr, dp);
        take %= mod;
        return dp[i][sum] = (take+untake)%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n,vector<int>(sum+1, -1));
        int ans = f(n-1,sum,arr,dp);
        return ans;
	}
};