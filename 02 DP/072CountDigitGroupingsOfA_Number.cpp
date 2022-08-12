#include<bits/stdc++.h>
using namespace std;

// GFG - Count Digit Groupings Of A Number

class Solution{
    vector<vector<int>> dp;
    int f(int i, int prev, int n, string str){
        if(i==n)
            return 1;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        int ans = 0;
        int sum = 0;
        int count = 0;
        for(int j = i; j<n; j++){
            sum += (str[j]-'0');
            if(sum>=prev){
                count++;
                ans += f(j+1,sum,n, str);
            }
        }
        return dp[i][prev] = ans;
    }
	public:
	int TotalCount(string str){
	    int n = str.size();
	    dp.resize(n, vector<int> (9*n+1, -1));
	    return f(0,0,n,str);
	}
};