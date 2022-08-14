#include<bits/stdc++.h>
using namespace std;

// LeetCode - 85

class Solution {
    int largest(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i==n || nums[st.top()]>=nums[i])){
                int height = nums[st.top()];
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> temp(m);
        for(int i = 0; i<n; i++){
            vector<int> temp2(m);
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '0')
                    temp2[j] = 0;
                else
                    temp2[j] += temp[j]+1;
            }
            int tempAns = largest(temp2);
            ans = max(ans,tempAns);
            temp = temp2;
        }
        return ans;
    }
};