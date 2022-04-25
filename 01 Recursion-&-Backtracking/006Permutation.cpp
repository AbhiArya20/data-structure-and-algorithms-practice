#include<bits/stdc++.h>
using namespace std;

// LeetCode - 46

class Solution {
    void permutations(int index, vector<int> &nums,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int innerIndex = index; innerIndex<nums.size(); innerIndex++){
            swap(nums[index], nums[innerIndex]);
            permutations(index+1, nums, ans);
            swap(nums[index], nums[innerIndex]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0,nums, ans);
        return ans;
    }
};




// LeetCode - 47
// Permutaion without duplicates

class Solution {
    void permutations(int index, vector<int> nums,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int innerIndex = index; innerIndex<nums.size(); innerIndex++){
            if(index != innerIndex && nums[innerIndex]==nums[index])
                continue;
            swap(nums[index], nums[innerIndex]);
            permutations(index+1, nums, ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permutations(0,nums,ans);
        return ans;
    }
};