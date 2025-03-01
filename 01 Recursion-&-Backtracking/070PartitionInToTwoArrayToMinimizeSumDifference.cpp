#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2035
// very tough
class Solution{
    void getSubset(vector<int> &nums, vector<vector<int>> &ans, int start, int count){
        for(int i = 0; i<(1<<count); i++){
            int sum = 0, posIdx = 0;
            for(int j = 0; j<count; j++){
                if(i&(1<<j)){
                    sum+=nums[j+start];
                    posIdx++;
                }
            }
            ans[posIdx].push_back(sum);
        }
    }
    public:
    int minimumDifference(vector<int> &nums){
        int n = nums.size();
        int sizeOfOne = n/2;
        vector<vector<int>> left(sizeOfOne+1), right(sizeOfOne+1);
        getSubset(nums, left, 0, sizeOfOne);
        getSubset(nums, right, sizeOfOne, sizeOfOne);
        int sum = accumulate(nums.begin(), nums.end(),0);
        for(auto &arr: right)
            sort(arr.begin(), arr.end());
        int ans = min(abs(sum-2*left[sizeOfOne][0]), abs(sum-2*right[sizeOfOne][0]));
        for(int i = 1; i<sizeOfOne; i++){
            for(auto v: left[i]){
                int rest = (sum-2*v)/2;
                int j = sizeOfOne-i;
                auto &whereTofind = right[j];
                int index = lower_bound(whereTofind.begin(), whereTofind.end(), rest) - whereTofind.begin();
                if(index != whereTofind.size())
                    ans = min(ans, abs(sum - 2*(v+whereTofind[index])));
            }
        }
        return ans;
    }
};