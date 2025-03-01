#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2155

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int right = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        int maxValue = left+right;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                right--;
            }else{
                left++;
            }
            maxValue = max(maxValue,left+right);
        }
        vector<int> ans;
        right = accumulate(nums.begin(),nums.end(),0);
        left = 0;
        if(left+right==maxValue){
            ans.push_back(0);
        }
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                right--;
            }else{
                left++;
            }
            if(left+right==maxValue){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};