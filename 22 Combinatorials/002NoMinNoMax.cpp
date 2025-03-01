#include<bits/stdc++.h>
using namespace std;

// Practice link - https://www.codechef.com/problems/NMNMX

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int mod7 = 1e9+7;
    int mod6 = 1e9+6;
    vector<vector<long long>> dp;
    void nCr(int n, int r){
        dp.resize(n+5, vector<long long>(r+5, 0));
        for(int i = 0; i<=r; i++)
            dp[i][i] = 1;
        for(int i = 0; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=i && j<r; j++){
                dp[i][j] = ((dp[i-1][j-1]%mod6)+(dp[i-1][j]%mod6))%mod6;
            }
        }
    }
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a)%mod7;
            a = (a * a)%mod7;
            b >>= 1;
        }
        return res;
    }
    public:
    int getAns(vector<int> &arr, int k){
        sort(arr.begin(),arr.end());
        int n = arr.size();
        long long ans = 1;
        nCr(n,k);
        vector<long long> validOcc(n);
        long long total = dp[n-1][k-1];
        for(int i = 1; i<=n/2; i++){
            long long maxi = 0;
            long long mini = 0;
            if(i>=k-1){
                maxi = dp[i][k-1];
            }
            if(n-i-1>=k-1){
                mini = dp[n-i-1][k-1];
            }
            long long valid = (total - maxi + mod6)%mod6;
            valid = (valid - mini + mod6)%mod6;
            validOcc[i] = valid;
            validOcc[n-1-i] = valid;
        }
        for(int i = 0; i<n-1; i++){
            long long powe = binpow(arr[i] , validOcc[i]);
            ans = (ans*powe)%mod7;
        }
        return ans;
    }
};