#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2499

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> um;
        long long ans = 0;
        int count = 0;
        int dominant = 0;
        int dominantCount = 0;
        for(int i = 0; i<n; i++){
            if(nums1[i]==nums2[i]){
                ans += i;
                um[nums1[i]]++;
                count++;
                if(um[nums1[i]]>dominantCount){
                    dominantCount = um[nums1[i]];
                    dominant = nums1[i];
                }
            }
        }
        for(int i = 0; i<n && count; i++){
            if(dominantCount > count/2 && nums1[i]!=nums2[i] && nums1[i]!=dominant && nums2[i]!=dominant){
                ans += i;
                count++;
            }
        }
        if(dominantCount > count/2)
            return -1;
        return ans;
    }
};