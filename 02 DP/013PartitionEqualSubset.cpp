#include<bits/stdc++.h>
using namespace std;

// LeetCode - 416

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        // subset sum
        sum/=2; 
        int n = nums.size();
        vector<int>dp (sum+1);
        dp[0]=1;
        for(int i = 0; i<n;i++){
            for(int j = sum; j>=nums[i]; j--){
                if(dp[j-nums[i]])
                    dp[j]=1;
            }
        }
        return dp[sum];
    }
};


// GFG - Print Partition Equal Subset
class Solution{
    pair<vector<int>,vector<int>> subset(vector<int> arr){
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2)
            return {{},{}};
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        for(int i = 0; i<=n; i++)
            dp[i][0]=true;
        for(int i = 1; i<=n; i++){
            for(int s = 1; s<=sum; s++){
                dp[i][s] = dp[i-1][s];
                if(arr[i-1]<=s){
                    dp[i][s] |= dp[i-1][s-arr[i-1]];
                }
            }
        }
        vector<int> s1, s2;
        if(dp[n][sum])
            return {{},{}};
        int i = n;
        int s = sum;
        while(i>0 && s>=0){
            i--;
            if(dp[i][s]){
                s2.push_back(arr[i]);
            }else if(dp[i][s-arr[i]]){
                s1.push_back(arr[i]);
                s -= arr[i];
            }
        }
        return {s1,s2};
    }
};