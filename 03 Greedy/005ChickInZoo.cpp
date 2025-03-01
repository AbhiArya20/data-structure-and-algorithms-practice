#include<bits/stdc++.h>
using namespace std;

// GFG - Cheek In Zoo

class Solution {
public:
	long long int NoOfChicks(int n){
	    long long int ans = 1;
	    vector<long long int> dp(n+10);
	    dp[6] = 1;
	    long long int cur = 1;
	    for(int i = 1; i<n; i++){
	        cur -= dp[i];
	        dp[i+6] = 2*cur;
	        cur += 2*cur;
	        ans = cur;
	    }
	    return ans;
	}
};