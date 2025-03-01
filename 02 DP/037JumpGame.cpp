#include<bits/stdc++.h>
using namespace std;

// GFG - Jump Game
// LeetCode - 55

class Solution {
  public:
    int canReach(int a[], int n) {
        int reach = a[0];
        for(int i = 0; i<n; i++){
            if(reach<i)
                return 0;
            reach = max(reach, a[i]+i);
        }
        return 1;
    }
};


// LeetCode - 45

class Solution {
    int f(int i,int n, vector<int> &nums, vector<int> &dp){
        if(i==n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int mini = 1e9;
        for(int j = 1; j<=nums[i]; j++){
            if(i+j<n)
                mini = min(mini, 1+f(i+j, n, nums, dp));
        }
        return dp[i] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,n,nums,dp);
    }
};


// LeetCode - 1696

class Solution { // Memoization - Not Accepted
    int f(int i,int n,int k, vector<int> &nums, vector<int> &dp){
        if(i==n-1)
            return nums[i];
        if(dp[i]!=-1)
            return dp[i];
        int maxi = -1e9;
        for(int j = 1; j<=k; j++){
            if(i+j<n)
                maxi = max(maxi, nums[i]+f(i+j, n,k, nums, dp));
        }
        return dp[i] = maxi;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,n,k,nums,dp);
    }
};

class Solution { // Tabulation - Not Accepted
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            int maxi = -1e9;
            for(int j = 1; j<=k; j++){
                if(i+j<n)
                    maxi = max(maxi, nums[i]+dp[i+j]);
            }
            dp[i]=maxi;
        }
        return dp[0];
    }
};

class Solution { // Accepted storing the calulated values in priority queue
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1], n-1});
        for(int i = n-2; i>=0; i--){
            while(pq.top().second>i+k)
                pq.pop();
            dp[i]=pq.top().first+nums[i];
            pq.push({dp[i],i});
        }
        return dp[0];
    }
};