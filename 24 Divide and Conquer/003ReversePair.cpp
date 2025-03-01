#include<bits/stdc++.h>
using namespace std;

// LeetCode - 493

class Solution {
    int merge(vector<int> & nums,int low,int mid,int high,vector<int> & arr){
        int count=0;
        int j = mid;
        for(int i=low;i<mid;i++){
            while(j<=high && nums[i]>(2*(long)nums[j]))
                j++;
            count+=j-mid;
        }
        int idx=low;
        int i=low;
        j=mid;
        while(i<mid && j<=high){
            if(nums[i]<=nums[j]){
                arr[idx++]=nums[i++];
            }else{
                arr[idx++]=nums[j++];
            }
        }
        while(i<mid){
            arr[idx++]=nums[i++];
        }
        while(j<=high){
            arr[idx++]=nums[j++];
        } 
        for(int l=low;l<=high;l++){
            nums[l]=arr[l];
        }
        return count;
    }
    int mergesort(vector<int> & nums,int low,int high,vector<int> & arr){
        int count=0;
        if(low<high){
            int mid=(low+high)/2;
            count+=mergesort(nums,low,mid,arr);
            count+=mergesort(nums,mid+1,high,arr);
            count+=merge(nums,low,mid+1,high,arr);
        }
        return count;
    }
    public:
    int reversePairs(vector<int> & nums) {
        vector<int> arr = nums;
        return mergesort(nums,0,nums.size()-1,arr);
    }
};