#include<bits/stdc++.h>
using namespace std;

// LeetCode - 42

class Solution{
    public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n),right(n);
        int leftMaxi = 0;
        for(int i = 0; i<n; i++){
            left[i] = leftMaxi;
            leftMaxi = max(leftMaxi, arr[i]);
        }
        int rightMaxi = 0;
        for(int i = n-1; i>=0; i--){
            right[i] = rightMaxi;
            rightMaxi = max(rightMaxi, arr[i]);
        }
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            int val = min(left[i],right[i])-arr[i];
            if(val>0)
                ans += val;
        }
        return ans;
    }
};


class Solution{
    public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int left = 0, leftMax = arr[0];
        int right = n-1, rightMax = arr[n-1];
        while(left<right){
            if(leftMax<rightMax){
                left++;
                leftMax = max(leftMax, arr[left]);
                if(leftMax>arr[left]){
                    ans += leftMax - arr[left];
                }
            }else{
                right--;
                rightMax = max(rightMax, arr[right]);
                if(rightMax>arr[right])
                    ans += rightMax - arr[right];
            }      
        }
        return ans;
    }
};