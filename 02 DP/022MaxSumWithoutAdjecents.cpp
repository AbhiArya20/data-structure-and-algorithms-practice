#include<bits/stdc++.h>
using namespace std;

// GFG - Max Sum Without Adjacents
// LeetCode - 198

class Solution{
    int f(int i,int *arr, int n, vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int untake = f(i+1, arr, n, dp);
        int take = arr[i] + f(i+2, arr, n, dp);
        return dp[i] = max(untake , take);
    }
public:
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    return f(0,arr, n, dp);
	}
};


// LeetCode - 213
class Solution {
    int f(int i,vector<int> &arr, int n, vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int untake = f(i+1, arr, n, dp);
        int take = arr[i] + f(i+2, arr, n, dp);
        return dp[i] = max(untake , take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        int val = nums[n-1];
        nums.pop_back();
        int ans1 = f(0,nums,n-1,dp);
        nums.push_back(val);
        nums.erase(nums.begin());
        dp.clear();
        dp.resize(n, -1);
        int ans2 = f(0, nums,n-1, dp);
        return max(ans2,ans1);
    }
};


// GFG - Max Sum without Adjacents 2

class Solution{
    int f(int i,int c, vector<int> &a, vector<vector<int>> &dp){
        if(i == a.size())
            return 0;
        if(dp[i][c]!=-1)
            return dp[i][c];
        int untake = f(i+1,0,a,dp);
        int take = 0;
        if(c<2){
            take = a[i] + f(i+1, c+1, a, dp);
        }
        return dp[i][c] = max(take , untake);
    }
  public:
  int findMaxSum(vector<int>& a){
      int n = a.size();
      vector<vector<int>> dp(n+1,vector<int>(3,-1));
      return f(0,0,a,dp);
  }
};
