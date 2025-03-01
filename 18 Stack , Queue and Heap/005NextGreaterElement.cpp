#include<bits/stdc++.h>
using namespace std;

// GFG - Next Greater Element

class Solution{
    vector<int> nextGreaterElement(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty())
                ans[i]=-1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
};