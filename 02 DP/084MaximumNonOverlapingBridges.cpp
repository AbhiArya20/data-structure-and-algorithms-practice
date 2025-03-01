#include<bits/stdc++.h>
using namespace std;

// GFG - Building Bridges

class Solution{
    public:
    int buildingBridges(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),[&](vector<int> &a, vector<int> &b){
            return a[0]==b[0] ? a[1]<=b[1] : a[0]<=b[0];
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