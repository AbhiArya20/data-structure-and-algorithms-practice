#include<bits/stdc++.h>
using namespace std;

// LeetCode - 335

class Solution {
    void merge(vector<vector<int>> &nums, int s, int e, int mid, vector<vector<int>> &temp, vector<int> &ans){
        int i = s;
        int j = mid+1;
        int k = s;
        int count = 0;
        while(i<=mid && j<=e){
            if(nums[i][0]>nums[j][0]){
                count++;
                temp[k++] = nums[j++];
            }else{
                ans[nums[i][1]]+=count;
                temp[k++] = nums[i++];
            }
        }
        while(i<=mid){
            ans[nums[i][1]]+=count;
            temp[k++] = nums[i++];
        }
        while(j<=e){
            temp[k++] = nums[j++];
        }
        for(int i = s; i<=e; i++)
            nums[i] = temp[i];
    }
    void countInversion(vector<vector<int>> &nums, int s, int e, vector<vector<int>> &temp,vector<int> &ans){
        if(s<e){
            int mid = (s+e)>>1;
            countInversion(nums,s,mid,temp,ans);
            countInversion(nums,mid+1,e,temp,ans);
            merge(nums,s,e,mid,temp,ans);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<vector<int>> temp(n),newNums;
        for(int i = 0; i<n; i++){
            newNums.push_back({nums[i],i});
        }
        countInversion(newNums,0,n-1,temp,ans);
        return ans;
    }
};