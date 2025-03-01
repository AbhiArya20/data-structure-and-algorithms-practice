#include<bits/stdc++.h>
using namespace std;

// LeetCode - 169

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(nums[i]==element)
                count++;
            else
                count--;
            if(count == 0){
                element = nums[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==element)
                count++;
        }
        return (count > n/2)? element : -1;
    }
};

class Solution { // Another approach
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(auto v: nums)
            um[v]++;
        for(auto v: um)
            if(v.second>n/2)
                return v.first;
        return -1;
    }
};

class Solution { // Another approach
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN;
        for(auto v: nums){
            if(v==prev){
                count++;
            }else{
                count = 1;
            }
            if(count > n/2)
                return v;
            prev = v;
        }
        return -1;
    }
};


// LeetCode - 229

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1 = INT_MIN;
        int count1 = 0;
        int element2 = INT_MIN;
        int count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==element1)
                count1++;
            else if(nums[i]==element2)
                count2++;
            else if(count1 == 0){
                element1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                element2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==element1)
                count1++;
            if(nums[i]==element2)
                count2++;
        }
        vector<int> ans;
        if(count1> n/3)
            ans.push_back(element1);
        if(count2> n/3)
            ans.push_back(element2);
        return ans;
    }
};


class Solution { // Another Approach
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        vector<int> ans;
        for(auto v: nums)
            um[v]++;
        for(auto v: um)
            if(v.second> n/3)
                ans.push_back(v.first);
        return ans;
    }
};


class Solution { // Another Approach
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int count = 0;
        int prev = INT_MIN;
        for(auto v: nums){
            if(v==prev)
                count++;
            else
                count = 1;
            if(count> n/3){
                if(ans.size()==0 || ans[ans.size()-1]!=v)
                    ans.push_back(v);
            }
            prev = v;
        }
        return ans;
    }
};