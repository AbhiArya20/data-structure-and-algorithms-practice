#include<bits/stdc++.h>
using namespace std;

// LeetCode - 220 

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i>indexDiff){
                st.erase(nums[i-indexDiff-1]);
            }
            if(st.find(nums[i])!=st.end())
                return true;
            st.insert(nums[i]);
            if(st.size()==1)
                continue;
            auto it = st.find(nums[i]);
            if(st.begin() == it){
                it++;
                int next = *it;
                if(abs(next-nums[i])<=valueDiff)
                    return true;
            }
            else{
                it--;
                int prev = *it;
                it++;
                it++;
                if(it==st.end()){
                    if(abs(prev - nums[i])<=valueDiff)
                        return true;
                }else{
                    int next = *it;
                    if(abs(prev - nums[i])<=valueDiff || abs(next-nums[i])<=valueDiff)
                        return true;
                }
            }
        }
        return false;
    }
};


