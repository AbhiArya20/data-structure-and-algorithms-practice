#include<bits/stdc++.h>
using namespace std;

// LeetCode - 153

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = nums.size()-1;
        if(nums[i]<=nums[j])
            return nums[0];
        while(i<j){
            int mid = (i+j)>>1;
            if(nums[mid]>nums[j])
                i = mid+1;
            else
                j = mid;
        }
        return nums[i];
    }
};