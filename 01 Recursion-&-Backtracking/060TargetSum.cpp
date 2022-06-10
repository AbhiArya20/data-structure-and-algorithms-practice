#include<bits/stdc++.h>
using namespace std;

// LeetCode - 494

class Solution {
    int getAns(int i, int sum, vector<int> & nums, int target){
        if(i==nums.size()){
            return sum == target;
        }
        int ans = 0;
        ans += getAns(i+1,sum+nums[i],nums, target);
        ans += getAns(i+1,sum-nums[i],nums, target);
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return getAns(0,0,nums,target);
    }
};