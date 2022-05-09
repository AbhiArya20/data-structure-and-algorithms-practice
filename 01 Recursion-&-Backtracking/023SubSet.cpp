#include<bits/stdc++.h>
using namespace std;

// LeetCode - 78

class Solution {
    void subsets(int i, int n, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        subsets(i+1, n,nums, temp, ans);
        temp.push_back(nums[i]);
        subsets(i+1, n,nums, temp, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        subsets(0,n,nums, {}, ans);
        return ans;
    }
};

// LeetCode - 90
// Subset without duplicates

class Solution {
    void subsets(int i, int n, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int j = i; j<n; j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            subsets(j+1, n,nums, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        subsets(0,n,nums, {}, ans);
        return ans;
    }
};



// GFG - SubSet Sum

class Solution{
    void subsets(int i, int n,int sum, vector<int> &nums, vector<int> &ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        subsets(i+1, n, sum, nums, ans);
        subsets(i+1, n, sum+nums[i], nums, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        subsets(0,n,0,arr,ans);
        return ans;
    }
};


// Another method of subSet Using Power-Set
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<(int)pow(2,n); i++){
            int val = i;
            int idx = n-1;
            vector<int> temp;
            while (val)
            {
                if(val&1){
                    temp.push_back(nums[idx]);
                }
                idx--;
                val = val>>1;
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};