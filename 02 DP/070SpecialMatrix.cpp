#include<bits/stdc++.h>
using namespace std;

// GFG - Special Matrix

class Solution {
    int mod = 1e9+7;
    unordered_map<int,unordered_set<int>> um;
    vector<vector<int>> dp;
    long long f(int i, int j, int n, int m){
        if(i>=n || j>=m || (um.find(i)!=um.end() && um[i].find(j)!=um[i].end()))
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = (f(i+1,j,n,m)+f(i,j+1,n,m))%mod;
    }
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    for(auto v: blocked_cells)
	        um[v[0]-1].insert(v[1]-1);
        if(um.find(0)!=um.end() && um[0].find(0)!=um[0].end())
	        return 0;
	    dp.resize(n+1,vector<int>(m+1, -1));
	   return f(0,0,n,m);
	}
};