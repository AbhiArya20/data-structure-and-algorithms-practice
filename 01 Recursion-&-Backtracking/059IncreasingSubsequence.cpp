#include<bits/stdc++.h>
using namespace std;

// LeetCode - 491

class Solution {
    void getAns(int i, int n,vector<int>& nums, vector<int> &temp,vector<vector<int>> &ans,int prev){
        if(i==n){
            if(temp.size() > 1){
                ans.push_back(temp);
            }
            return;
        }
        if(prev != nums[i])
            getAns(i+1,n,nums,temp,ans,prev);
        if(prev<=nums[i]){
            temp.push_back(nums[i]);
            getAns(i+1, n, nums, temp,ans, nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return {};
        vector<vector<int>> ans;
        vector<int> temp;
        getAns(0,n,nums,temp,ans,-1000);
        return ans;
    }
};