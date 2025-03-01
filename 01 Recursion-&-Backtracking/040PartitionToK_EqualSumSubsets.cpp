#include<bits/stdc++.h>
using namespace std;

// LeetCode - 698

class Solution {
    int f(int i ,int mask, int k,int cur, int &sum, vector<int>& nums,unordered_map<int,int> &dp){
        if(k==0)
            return k==0;
        int key = i+mask*4+cur+k*10;
        if(dp.find(key)!=dp.end())
            return dp[key];
        if(sum==cur)
            return dp[key] = f(0,mask,k-1,0, sum , nums, dp);
        int n = nums.size();
        for(int j = i; j<nums.size(); j++){
            if((mask & (1<<n-1-j))  && cur+nums[j]<=sum){
                if(f(j+1,mask^(1<<n-1-j), k ,cur+nums[j], sum, nums, dp)){
                    return dp[key]= 1;
                }     
            }
        }
        return dp[key] = 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto v: nums)
            sum+=v;
        if(sum%k)
            return false;
        int tofindSum = sum/k;
        int n = nums.size();
        int mask = (1<<n)-1;
        unordered_map<int,int> dp;
        int ans = f(0,mask, k, 0, tofindSum, nums, dp);
        return ans;
    }
};