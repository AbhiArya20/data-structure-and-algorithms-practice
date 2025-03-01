#include<bits/stdc++.h>
using namespace std;

// LeetCode - 31

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if(i!=-1){
            int j = n-1;
            while(j>i && nums[j]<=nums[i]){
                j--;
            }
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};