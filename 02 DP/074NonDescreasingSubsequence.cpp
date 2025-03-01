#include<bits/stdc++.h>
using namespace std;

// GFG - Non-Decreasing Subsequence

class Solution{ // Non-Accepted
    map<vector<int>,int> dp;
    int f(int i, int p, int k, int n, int arr[]){
        if(k==0)
            return 0;
        if(i==n)
            return 1e9;
        if(dp.find({i,p,k})!=dp.end())
            dp[{i,p,k}];
        int untake = f(i+1, p, k, n, arr);
        int take = INT_MAX;
        if(p == -1 || arr[p]<=arr[i])
            take = arr[i]+f(i+1,i,k-1,n,arr);
        return dp[{i,p,k}] = min(take,untake);
    }
	public:
	int minSum(int arr[], int n, int k){
	    int ans = f(0, -1, k, n, arr);
        if(ans == 1e9)
            return -1;
        return ans;
	} 
};




class Solution{ // Accepted
    int dp[1005][1005];
    int f(int arr[], int i, int n, int k){
	    if(k==0) return 0;
	    if(dp[i][k]!=-1)
    	    return dp[i][k];
	    int ans = 1e9;
	    for(int j=i+1; j<n ; j++)
	        if(arr[j] >= arr[i])
	            ans = min(ans, arr[j] + f(arr,j,n,k-1));
	    return dp[i][k] = ans;
	}
	public:
	int minSum(int arr[], int n, int k){
	    memset(dp, -1, sizeof(dp));
	    int ans = 1e9;
	    for(int i = 0; i<=n-k; i++)
    	    ans = min(ans,arr[i]+f(arr,i,n,k-1));
        if(ans >= 1e9)
            return -1;
        return ans;
	} 
};