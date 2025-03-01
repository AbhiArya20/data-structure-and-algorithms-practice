#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1

class Solution { // Using map
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        int i = 0;
        for(int ele: nums){
            if(s.find(target-ele)!=s.end()){
                return {i,s[target-ele]};
            }
            s[ele] = i;
            i++;
        }
        return {-1,-1};
    }
};

// LeetCode - 167

class Solution { // Using two pointer
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int i= 0;
        int j=n-1;
        while(i<j){
            int s = arr[i]+arr[j];
            if(s==target)
               return {i+1,j+1};
            if(s<target)
                i++;
            else
                j--;
        }
        return {-1,-1};
    }
};


// LeetCode - 15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<=2){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int k = 0; k<n; k++){
            int cur_val = nums[k];
            int target = -cur_val;
            int i = k+1;
            int j = n-1;
            while(i<j){
               int sum = nums[i]+nums[j];
               if(sum == target ){
                   if(st.find({cur_val, nums[i], nums[j]})==st.end()){
                       ans.push_back({cur_val, nums[i], nums[j]});
                       st.insert({cur_val, nums[i], nums[j]});
                   }
                   j--;
               }
               else if(sum < target){
                   i++;
               }else{
                   j--;
               }
            }
            
        }
        return ans;
    }
};


// LeetCode - 923

class Solution {
    int mod = 1e9+7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 0;
        unordered_map<int,int> um;
        for(int i = 0; i<n; i++){
            int val = target - arr[i];
            ans += um[val];
            ans %= mod;
            for(int j = 0; j<i; j++){
                um[arr[j]+arr[i]]++;
            }
        }
        return ans;
    }
};