#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Time

class Solution{
	public:
	int minTimeForWritingChars(int N, int I, int D, int C) { 
	    vector<int> dp(N+1);
	    dp[1] = I;
	    for(int i = 2; i<=N; i++){
	        if(i%2)
	            dp[i] = min(dp[i-1]+I, dp[(i+1)/2]+C+D);
	        else
	            dp[i] = min(dp[i-1]+I, dp[i/2]+C);
	    }
	    return dp[N];
	} 
};