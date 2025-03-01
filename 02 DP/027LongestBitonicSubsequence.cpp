#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Bitonic Subsequence


class Solution{
    vector<int> lis(vector<int> &arr, int n){
        vector<int> dp(n, 1);
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<i; j++){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return dp;
    }
    
    vector<int> lds(vector<int> &arr, int n){
        vector<int> dp(n, 1);
        for(int i = n-1; i>=0; i--){
            int sum = 0;
            for(int j = n-1; j>i; j--){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }
        return dp;
    }
	public:
	int LongestBitonicSequence(vector<int> &arr){
	    int n = arr.size();
	    auto v1 = lis(arr, n);
        auto v2 = lds(arr, n);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int val = v1[i]+v2[i]-1;
            ans = max(ans, val);
        }
        return ans;
	}
};





// GFG - Maximum Sum Bitonic Subsequence
class Solution{
    vector<int> lis(int arr[], int n){
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<i; j++){
                if(arr[i]>arr[j]){
                    sum = max(sum , dp[j]);
                }
            }
            dp[i] = arr[i]+sum;
        }
        return dp;
    }
    
    vector<int> lds(int arr[], int n){
        vector<int> dp(n, 1);
        for(int i = n-1; i>=0; i--){
            int sum = 0;
            for(int j = n-1; j>i; j--){
                if(arr[i]>arr[j]){
                    sum = max(sum , dp[j]);
                }
            }
            dp[i] = arr[i]+sum;
        }
        return dp;
    }
	public:
	int maxSumBS(int arr[] , int n){
        auto v1 = lis(arr, n);
        auto v2 = lds(arr, n);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int val = v1[i]+v2[i]-arr[i];
            ans = max(ans, val);
        }
        return ans;
    }
};