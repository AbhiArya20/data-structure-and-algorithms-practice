#include<bits/stdc++.h>
using namespace std;

// GFG - Box Stacking

class Solution{
    public:
    int maxHeight(int height[],int width[],int length[],int n){
        vector<vector<int>> arr;
        for(int i = 0; i<n; i++){
            arr.push_back({height[i], max(width[i],length[i]), min(width[i],length[i])});
            arr.push_back({width[i], max(height[i],length[i]), min(height[i],length[i])});
            arr.push_back({length[i], max(width[i],height[i]), min(width[i],height[i])});
        }
        sort(arr.begin(), arr.end(),[&](vector<int> &a, vector<int> &b){
            return (b[1]*b[2]<a[1]*a[2]);
        });
        int ans = 0;
        vector<int> dp(3*n);
        for(int i = 0; i<3*n; i++){
            for(int j = 0; j<i; j++){
                if(arr[j][1]>arr[i][1] && arr[j][2]>arr[i][2]){
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i]+=arr[i][0];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};