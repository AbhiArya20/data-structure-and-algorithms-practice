#include<bits/stdc++.h>
using namespace std;

// GFG - Get Minimum Squares
class Solution{
    vector<int> dp;
    int f(int n){
        if(n == 0){
            return 0;
        }
        if(dp[n]!=-1)
            return dp[n];
        int ans = n+1;
        for(int i = 1; i*i<=n; i++){
            if((n-(i*i))>=0){
                ans = min(ans, 1+f(n-(i*i)));
            }
        }
        return dp[n] = ans;
    }
	public:
	int MinSquares(int n){
	    dp.resize(n+1,-1);
	    return f(n);
	}
};