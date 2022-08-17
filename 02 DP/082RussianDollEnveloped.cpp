#include<bits/stdc++.h>
using namespace std;

// LeetCode - 354

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),[&](vector<int> &a, vector<int> &b){
            return a[0]==b[0] ? a[1]>=b[1] : a[0]<=b[0];
        });
        vector<int> dp;
        dp.push_back(arr[0][1]);
        int ans=1;
        for(int i = 0; i<n; i++){
            auto end = lower_bound(dp.begin(), dp.end(), arr[i][1]);
            if(end == dp.end())
                dp.push_back(arr[i][1]);
            else
                *end = arr[i][1];
        }
        return dp.size();
    }
};


// Follow-up
// LeetCode - 1691

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> arr;
        for(int i = 0; i<n; i++){
            arr.push_back({cuboids[i][0], max(cuboids[i][1],cuboids[i][2]), min(cuboids[i][1],cuboids[i][2]), i});
            arr.push_back({cuboids[i][1], max(cuboids[i][0],cuboids[i][2]), min(cuboids[i][0],cuboids[i][2]), i});
            arr.push_back({cuboids[i][2], max(cuboids[i][0],cuboids[i][1]), min(cuboids[i][0],cuboids[i][1]), i});
        }
        sort(arr.begin(), arr.end(),[&](vector<int> &a, vector<int> &b){
            return (b[0]*b[1]*b[2]<a[0]*a[1]*a[2]);
        });
        int ans = 0;
        vector<int> dp(3*n);
        for(int i = 0; i<3*n; i++){
            for(int j = 0; j<i; j++){
                if(arr[i][3]==arr[j][3])
                    continue;
                if(arr[j][1]>=arr[i][1] && arr[j][2]>=arr[i][2] && arr[j][0]>=arr[i][0]){
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i]+=arr[i][0];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};