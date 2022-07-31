#include<bits/stdc++.h>
using namespace std;

// GFG - Maximize Dot Product

class Solution{
	int f(int i, int j, int n, int m, int a[],int b[], vector<vector<int>> &dp){
	    if(m-j > n-i)
	       return 0;
	    if(i==n)
	        return 0;
	    if(j==m-1 ){
	      int val = a[i];
	      while(i<n)
	         val = max(val,a[i++]);
	      return val*b[j];
	    }
	    if(dp[i][j] != -1)
	        return dp[i][j];
	    int untake = f(i+1,j,n,m,a,b,dp);
	    int take = a[i] * b[j] + f(i+1,j+1,n,m,a,b,dp);
	    return dp[i][j] = max(untake,take);
	}	
	public:
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
	    vector<vector<int>> dp(n,vector<int> (m,-1));
		return f(0,0,n,m,A,B,dp);
	} 
};