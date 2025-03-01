#include<bits/stdc++.h>
using namespace std;

// GFG - Stacking up disc

class Solution{
    public:
    int StackingUpDiscs(int N,int R[],int H[]){
        vector<vector<int>> arr;
        for(int i = 0;i<N;i++){
            arr.push_back({R[i],H[i]});
        }
        sort(arr.begin(),arr.end(),[&](vector<int> &a, vector<int> &b){
            return a[0]*a[1]<b[0]*b[1];
        });
        vector<int> dp(N,0);
        int ans=0;
        for(int i = 0; i<N; i++ ){
            for(int j = 0; j<i;j++){
                if(arr[j][0]<arr[i][0] && arr[j][1]<arr[i][1])
                    dp[i] = max(dp[i],dp[j]);
            }
            dp[i]+=arr[i][1];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};