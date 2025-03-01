#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2317

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(auto v: nums)
            ans|=v;
        return ans;
    }
};