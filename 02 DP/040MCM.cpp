#include<bits/stdc++.h>
using namespace std;

// GFG - MCM

class Solution{
    int f(int s, int e, int arr[], vector<vector<int>> &dp){
        if(s == e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = 1e9;
        for(int i = s; i<e; i++){
            int val = arr[s-1]*arr[i]*arr[e] + f(s, i, arr, dp) + f(i+1,e,arr, dp);
            ans = min(ans, val);
        }
        return dp[s][e] = ans;
    }
public:
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return f(1,N-1,arr, dp);
    }
};



// GFG - Brackets in MCM

class Solution{
    void getAns(int s, int e,int n, char& name, vector<vector<int>> &breakPoint, string &ans){
        if(s==e){
            ans+=name;
            name++;
            return;
        }
        ans+='(';
        getAns(s,breakPoint[s][e],n,name,breakPoint,ans);
        getAns(breakPoint[s][e]+1,e,n,name,breakPoint,ans);
        ans+=')';
    }
public:
    string matrixChainOrder(int p[], int n){
         vector<vector<int>> dp(n, vector<int>(n));
         vector<vector<int>> breakPoint(n, vector<int>(n));
        for(int i = n-2; i>=1; i--){
             for(int j = i+1; j<n; j++){
                 int ans = 1e9;
                 for(int k = i; k<j; k++){
                     int val = p[i-1] * p[k] * p[j] + dp[i][k] + dp[k+1][j];
                     if(val<ans){
                         breakPoint[i][j] = k;
                     }
                     ans = min(ans, val);
                 }
                 dp[i][j] = ans;
             }
         }
         string ans = "";
         char name = 'A';
         getAns(1,n-1,n,name,breakPoint,ans);
         return ans;
    }
};