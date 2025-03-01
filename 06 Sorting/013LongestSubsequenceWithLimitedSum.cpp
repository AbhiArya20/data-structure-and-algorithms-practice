#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2389

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans,prefixSum;
        sort(nums.begin(),nums.end());
        prefixSum.push_back(0);
        for(auto v: nums){
            prefixSum.push_back(v+prefixSum[prefixSum.size()-1]);
        }
        for(auto q: queries){
            auto idx = lower_bound(prefixSum.begin(),prefixSum.end(),q)-prefixSum.begin();
            if(idx>n || prefixSum[idx]>q)
                idx--;
            ans.push_back(idx);
        }
        return ans;
    }
};