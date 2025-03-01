#include<bits/stdc++.h>
using namespace std;

// GFG - Number of paths in a matrix with k coins
class Solution {
    int n;
    long long solve(int i, int j,vector<vector<int>> &arr, int k, vector<vector<vector<long long>>> &dp)
    {
        if(i>=n || j>=n || k<0)return 0;
        
        if(dp[i][j][k] != -1)return dp[i][j][k];
        
        if(i==n-1 && j==n-1){
            return (k-arr[i][j]==0) ? 1 : 0;
        }
        return dp[i][j][k] = solve(i+1, j, arr, k-arr[i][j], dp) + solve(i, j+1, arr, k-arr[i][j], dp);
    }
public:
    long long numberOfPath(int N, int k, vector<vector<int>> arr){
        n = N;
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(k+1, -1)));
        return solve(0,0,arr, k, dp);
    }
};