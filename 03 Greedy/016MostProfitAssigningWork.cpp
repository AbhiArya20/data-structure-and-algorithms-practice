#include<bits/stdc++.h>
using namespace std;

// LeetCode - 826

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>> difPro;
        for(int i = 0; i<n; i++){
            difPro.push_back({profit[i], difficulty[i]});
        }
        sort(difPro.begin(),difPro.end());
        sort(worker.begin(),worker.end());
        int i = n-1;
        int j = m-1;
        int ans = 0;
        while(j>=0 && i>=0){
            if(difPro[i].second>worker[j]){
                i--;
            }else{
                ans+=difPro[i].first;
                j--;
            }
        }
        return ans;
    }
};