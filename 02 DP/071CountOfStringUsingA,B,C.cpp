#include<bits/stdc++.h>
using namespace std;

// GFG - Count of strings that can be formed using a, b and c under given constraints

class Solution{
    vector<vector<vector<long long int>>> dp;
    long long int f(int i,int b, int c, int n){
        if(i==n)
            return 1;
        if(dp[i][b][c]!=-1)
            return dp[i][b][c];
        long long int ans = f(i+1,b,c,n);
        if(b)
            ans += f(i+1, b-1, c, n);
        if(c)
            ans += f(i+1, b, c-1, n);
        return dp[i][b][c] = ans;
    }
    long long int countStr(long long int n){
        dp.resize(n,vector<vector<long long int>>(2,vector<long long int>(3,-1)));
        long long int ans = f(0,1,2,n);
        cout<<ans<<endl;
        return ans;
    }
};

class Solution{
    long long int countStr(long long int n){
        long long int count = 0;
        if(n>=1){
            count += 1;
            count += n;
            count += n;
            if(n>=2){
            count += n*(n-1);
            count += n*(n-1)/2;
            if(n>=3){
                count += (n-2)*(n-1)*n/2;
            }
            }
        }
        return count;
    }
};


