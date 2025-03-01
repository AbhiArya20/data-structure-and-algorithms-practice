#include<bits/stdc++.h>
using namespace std;

// LeetCode - 84

class Solution {
    vector<int> leftMini(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
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
    vector<int> rightMini(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())
                ans[i]=n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        auto left = leftMini(heights);
        auto right = rightMini(heights);
        for(int i = 0; i<n; i++){
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width = i;
                if(!st.empty())
                    width = (i-st.top()-1);
                ans = max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};