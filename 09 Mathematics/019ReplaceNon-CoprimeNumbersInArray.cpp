#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2197

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int val1 = nums[i];
            while(ans.size() && __gcd(val1,ans[ans.size()-1]) > 1){
                long long val2 = ans[ans.size()-1];
                ans.pop_back();
                int lcm = val1*val2/__gcd((long long)val1,val2);
                val1 = lcm;
            }
            ans.push_back(val1);
        }
        return ans;
    }
};