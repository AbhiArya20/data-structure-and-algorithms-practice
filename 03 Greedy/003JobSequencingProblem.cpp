#include<bits/stdc++.h>
using namespace std;

// GFG - Job Sequencing Problem
struct Job
{
    int profit,dead;
};

class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, [](Job a, Job b){
            return a.profit>b.profit;
        });
        vector<int> dp(100+1,0);
        int ans = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            int j = arr[i].dead;
            while(j>0 && dp[j]){
                j--;
            }
            if(j>0){
                dp[j] = 1;
                ans += arr[i].profit;
                count++;
            }
        }
        return {count,ans};
    } 
};