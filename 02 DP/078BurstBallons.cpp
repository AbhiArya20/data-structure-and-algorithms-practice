#include<bits/stdc++.h>
using namespace std;

// LeetCode - 312
class Solution {
    vector<vector<int>> dp;
    int f(int s, int e, vector<int> &arr){
        if(s>e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = 0;
        for(int i = s; i<=e; i++){
            int left = f(s, i-1, arr);
            int right = f(i+1, e, arr);
            int val = arr[s-1]*arr[i]*arr[e+1]+left+right;
            ans = max(ans, val);
        }
        return dp[s][e] = ans;
    }
public:
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n+3, vector<int> (n+3, -1));
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        return f(1,n,arr);
    }
};