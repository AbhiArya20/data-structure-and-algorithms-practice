#include<bits/stdc++.h>
using namespace std;

// GFG - Missing Number
// LeetCode - 268

int missingNumber(int A[], int n){
    for(int i = 0; i<n-1; i++){
        int correctPos = A[i]-1;
        if(A[i]-1<n-1 && A[i]!=A[correctPos]){
            swap(A[i],A[correctPos]);
            i--;
        }
    }
    for(int i = 0; i<n-1; i++){
        if(A[i]-1!=i)
            return i+1;
    }
    return n;
}



int missingNumber(int A[], int n){
    int sum = accumulate(A, A+(n-1),0);
    return ((n*(n+1))/2)-sum; 
}



int missingNumber(int A[], int n){
    int ans = 0;
    for(int i = 0; i<n-1; i++){
        ans^=A[i];
    }
    for(int i = 1; i<=n;i++)
        ans^=i;
    return ans;
}


// LeetCode - 287

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int curIndex = nums[i]-1;
            if(nums[i]!=nums[curIndex]){
                swap(nums[i],nums[curIndex]);
                i--;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i]-1!=i){
                return nums[i];
            }
        }
        return -1;
    }
};