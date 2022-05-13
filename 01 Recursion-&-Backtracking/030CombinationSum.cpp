#include<bits/stdc++.h>
using namespace std;

// LeetCode - 39

class Solution {
    void combination(int idx, int target,vector<int> &candidates,vector<int> &temp, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i<candidates.size(); i++){
            if(target>=candidates[i]){
                temp.push_back(candidates[i]);
                combination(i,target-candidates[i],candidates,temp,ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(0,target,candidates,temp,ans);
        return ans;
    }
};


// LeetCode - 40
// No same element allowed in single combination
class Solution {
    void combination(int idx, int target,vector<int> &candidates,vector<int> &temp, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i<candidates.size(); i++){
            if(idx!=i && candidates[i]==candidates[i-1])
                continue;
            if(target>=candidates[i]){
                temp.push_back(candidates[i]);
                combination(i+1,target-candidates[i],candidates,temp,ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combination(0,target,candidates,temp,ans);
        return ans;
    }
};



// LeetCode - 216
class Solution {
    void combination(int target,int k,vector<int> &temp, vector<vector<int>> &ans){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(k==0){
            return;
        }
        for(int i = 1;i<=9; i++){
            if(temp.size() && temp[temp.size()-1]>=i)
                continue;
            temp.push_back(i);
            combination(target-i,k-1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(n,k,temp,ans);
        return ans;
    }
};


