#include<bits/stdc++.h>
using namespace std;

// LeetCode - 77

class Solution {
    void combination(int idx, int k, int n, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i<=n; i++){
            temp.push_back(i);
            combination(i+1,k,n,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(1,k,n,temp,ans);
        return ans;
    }
};