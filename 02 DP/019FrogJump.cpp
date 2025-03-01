#include<bits/stdc++.h>
using namespace std;

// GFG - Count Number of Hops

class Solution{
    int mod = 1e9+7;
    int f(int i,vector<int> &dp){
        if(i<=0){
            return i == 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        long long ans = 0;
        for(int j = 1; j<4; j++){
            ans += f(i-j,dp);
            ans %= mod;
        }
        return dp[i] = (int)ans;
    }
    public:
    long long countWays(int n){
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};


// LeetCode - 403

class Solution {
    int f(int i,int val, int last,unordered_set<int> &stones, map<pair<int,int>, int> &dp){
        int n = stones.size();
        if(val == last)
            return true;
        if(stones.find(val)==stones.end())
            return false;
        if(val!=0 && i==0)
            return false;
        if(dp.find({val,i})!=dp.end())
            return dp[{val,i}];
        if(i==0)
            return dp[{val,i}] = f(1, 1,last,stones,dp);
        return dp[{val,i}] = f(i,val+i,last,stones,dp) || f(i+1,val+i+1,last,stones,dp) || f(i-1,val+i-1,last,stones,dp);
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<pair<int,int>, int> dp;
        unordered_set<int> stonesSet(stones.begin(), stones.end());
        return f(0,0,stones[n-1],stonesSet,dp);
    }
};