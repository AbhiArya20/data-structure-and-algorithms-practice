#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1755

class Solution {
    void subsetSum(vector<int> &arr, int start, int count, vector<long long> &ans){
        for(int i = 0; i<(1<<count); i++){
            long long sum = 0;
            for(int j = 0; j<count; j++){
                if(i&(1<<j)){
                    sum+=arr[j+start];
                }
            }
            ans.push_back(sum);
        }
    }
public:
    int minAbsDifference(vector<int>& arr, int target) {
        int n = arr.size();
        long long ans = INT_MAX;
        vector<long long> left, right;
        subsetSum(arr,0,n/2,left);
        subsetSum(arr,n/2, n-n/2, right);
        sort(right.begin(), right.end());
        for(auto c: left){
            long long r = target-c;
            int index = lower_bound(right.begin(), right.end(), r) - right.begin();
            if(index == right.size()){
                index--;
                ans = min(ans, abs(r-right[index]));
            }
            else if(right[index] == r){
                return 0;
            }else{
                if(index-1>=0)
                    ans = min(ans, abs(r-right[index-1]));
                ans = min(ans, abs(r-right[index]));                        
            }
        }
        return ans;
    }
};