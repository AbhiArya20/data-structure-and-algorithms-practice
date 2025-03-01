#include<bits/stdc++.h>
using namespace std;

// LeetCode - 862

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n+1);
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }
        deque<int> dq;
        int ans = n+1;
        for(int i = 0; i<n+1; i++){
            while(!dq.empty() && prefixSum[dq.back()]>=prefixSum[i])
                dq.pop_back();
            while(!dq.empty() && prefixSum[i]-prefixSum[dq.front()]>=k){
                ans = min(ans, i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        if(ans == n+1)
            return -1;
        return ans;
    }
};