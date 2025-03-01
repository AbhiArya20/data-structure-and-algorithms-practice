#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Sum Partition

class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr, arr+n, 0);
	    vector<int> dp(sum+1);
	    dp[0]=1;
	    for(int i = 0; i<n; i++){
	        for(int j = sum; j>=arr[i]; j--){
	            if(dp[j-arr[i]])
	                dp[j] = 1;
	        }
	    }
	    int ans = sum;
	    for(int i = 1; i<sum; i++){
	        if(dp[i])
	            ans = min(ans, abs(i-(sum-i)));
	    }
	    return ans;
	} 
};