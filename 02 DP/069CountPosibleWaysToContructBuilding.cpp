#include<bits/stdc++.h>
using namespace std;
// From here, I am try to make some variable globally to save time

// GFG - Count possible ways to construct buildings
class Solution{
    long long mod = 1e9+7;
    vector<long long> dp;
    long long f(int n){
        if(n <= 1)
            return n+1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = (f(n-1)+f(n-2))%mod;
    }
	public:
	int TotalWays(int N){
	    dp.resize(N+1,-1);
	    long long ans = f(N);
	    return (int)((ans*ans)%mod);
	}
};