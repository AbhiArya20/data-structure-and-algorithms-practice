#include<bits/stdc++.h>
using namespace std;

// LeetCode - 370

class Solution{
    public:
    vector<int> getAns(int n,vector<vector<int>> queries){
        vector<int> ans(n);
        for(auto que: queries){
            ans[que[0]] += que[2];
            if(que[1]+1<n)
                ans[que[1]+1] += - que[2]; 
        }
        for(int i = 1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};