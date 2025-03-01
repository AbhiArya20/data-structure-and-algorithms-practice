#include<bits/stdc++.h>
using namespace std;

// LeetCode - 540

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n%2==0)
            return -1;
        int i = 0; 
        int j = n-1;
        int ans = -1;
        while(i<j){
            int mid = (i+j)>>1;
            if(mid%2){
                if(mid-1>=0 && nums[mid]==nums[mid-1]){
                    i = mid+1;
                }else{
                    j = mid;
                }
            }else{
                if(mid+1<n && nums[mid]==nums[mid+1]){
                    i = mid+1;
                }else{
                    j = mid;
                }
            }
        } 
        return nums[i];
    }
};