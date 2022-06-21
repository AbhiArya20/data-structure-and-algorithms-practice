#include<bits/stdc++.h>
using namespace std;

// LeetCode - 805

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
    int splitArraySameAverage(vector<int> &nums){
        int n = nums.size();
        if (n == 1) return false;
        if (n == 2) return nums[0] == nums[1];
        int sizeOfOne = n/2;
        vector<vector<int>> left(sizeOfOne+1), right(n-sizeOfOne+1);
        getSubset(nums, left, 0, sizeOfOne);
        getSubset(nums, right, sizeOfOne, n-sizeOfOne);
        int sum = accumulate(nums.begin(), nums.end(),0);
        for(auto &arr: right)
            sort(arr.begin(), arr.end());
        for(int i = 0; i<sizeOfOne; i++){
            for(auto v: left[i]){
                for (int j = 0; j < right.size(); j++) {
                    if (i + j == 0 || i + j == nums.size()) continue;
                    double rest = ((1.0 * sum * (i + j)) / nums.size()) - v;
                    if (ceil(rest) != rest) continue;
                    auto whereTofind = right[j];
                    int index = lower_bound(whereTofind.begin(), whereTofind.end(), (int)rest) - whereTofind.begin();
                    if(index != whereTofind.size() && whereTofind[index] == rest)
                       return true;
               }
            }
        }
        return false;
    }
};