#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1944

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            int count = 0;
            while(!st.empty() && heights[st.top()]<=heights[i]){
                st.pop();
                count++;
            }
            if(count){
                if(st.empty()){
                    ans[i] = count;
                }else{
                    ans[i] = count+1;
                }
            }else{
                ans[i] = 1;
            }
            st.push(i);
        }
        ans[n-1] = 0;
        return ans;
    }
};