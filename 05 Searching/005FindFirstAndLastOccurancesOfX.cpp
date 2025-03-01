#include<bits/stdc++.h>
using namespace std;

// LeetCode - 34
// GFG - First And Last Occurrences of X

class Solution{
    int binarySearch(vector<int> &arr, int n, int x, int which){
        int left = 0;
        int right = n-1;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(arr[mid]==x){
                ans = mid;
                if(which){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else if(arr[mid]>x){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
    public:
    vector<int> searchRange(vector<int>& arr, int target){
        int n = arr.size();
        vector<int> ans;
        ans.push_back(binarySearch(arr,n,target,0));
        ans.push_back(binarySearch(arr,n,target,1));
        return ans;
    }
};