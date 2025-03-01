#include<bits/stdc++.h>
using namespace std;

// GFG - Number of distinct subsequence

class Solution{
    int mod = 1e9+7;
  public:	
	int distinctSubsequences(string s){
	    int n = s.size();
	    unordered_map<char,int> um;
        vector<long long> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            dp[i] = 2*dp[i-1];
            if(um.find(s[i-1])!=um.end())
                dp[i] -= dp[um[s[i-1]]];
            um[s[i-1]] = i-1;
        }
        return dp[n]%mod;
	}
};
