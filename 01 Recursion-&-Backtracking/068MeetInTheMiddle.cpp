#include<bits/stdc++.h>
using namespace std;
// This technique is to optimize the time complexity here is an optimization on finding subset sum.
// GFG - Meet In The Middle
// https://www.geeksforgeeks.org/meet-in-the-middle/

class Solution{
    void subsetSum(vector<long long> &arr, int start, int count, vector<long long> &ans){
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
    long long lesserOREqualSubSet(vector<long long> &arr, int target){
        int n = arr.size();
        long long ans = 0;
        vector<long long> left, right;
        subsetSum(arr,0,n/2,left);
        subsetSum(arr,n/2, n-n/2, right);
        sort(right.begin(), right.end());
        for(auto c: left){
            if(c<=target){
                int index = lower_bound(right.begin(), right.end(), target-c) - right.begin();
                if(index == right.size() || right[index]!=target-c)
                    index--;
                ans = max(ans, (c+right[index]));
            }
        }
        return ans;
    }
};