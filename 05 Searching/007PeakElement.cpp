#include<bits/stdc++.h>
using namespace std;

// GFG - Peek Element
// LeetCode - 162


// This problem is special case of Binary search
class Solution{
    public:
    int peakElement(int arr[], int n){
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left+right)>>1;
            if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
                return mid;
            }else if(arr[mid]<=arr[mid+1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
};