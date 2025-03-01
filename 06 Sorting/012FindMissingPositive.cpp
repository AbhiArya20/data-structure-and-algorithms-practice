#include<bits/stdc++.h>
using namespace std;

// LeetCode - 41
// GFG - Smallest Positive Missing Number

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        for(int i = 0; i<n; i++){
            if(nums[i]<=0 || nums[i]>=n){
                swap(nums[i],nums[j]);
                j--;
                i--;
            }else{
                int curPos = nums[i]-1;
                if(nums[i]!=nums[curPos]){
                    swap(nums[i],nums[curPos]);
                    i--;
                }
            }
            if(j<=i)
                break;
        }
        for(int i = 0; i<n; i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};