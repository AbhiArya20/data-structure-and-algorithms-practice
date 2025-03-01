#include<bits/stdc++.h>
using namespace std;

// GFG - Array removal

class Solution{ // DP
    int f(int s, int e, int k, vector<int> &arr, vector<vector<int>> &dp){
        if(arr[e]-arr[s]<=k)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int left = f(s+1, e, k, arr, dp);
        int right = f(s, e-1, k, arr, dp);
        return dp[s][e] = min(left, right)+1;
    }
    public:
    int removals(vector<int>& arr, int k){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0,n-1,k,arr, dp);
    }
};


class Solution{ // Binary search
    public:
    int removals(vector<int>& arr, int k){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = n-1;
        if(n==1)
            return 0;
        for(int i=0;i<n;i++){
            int index = upper_bound(arr.begin()+i,arr.end(), arr[i]+k) - arr.begin() - 1;
            ans = min(ans, n-(index-i+1));
        }
        return ans;
    }
};


class Solution{ // Sliding Window
    public:
    int removals(vector<int>& arr, int k){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0, j = 0; i<n; i++){
            int dif = arr[i]-arr[j];
            while(i>=j && dif > k)
                dif = arr[i] - arr[++j];
            ans = max(ans, i-j+1);
        }
        return n-ans;
    }
};