#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1687

class Solution { // O(N^2) - Not Accepted
    vector<vector<int>> dp;
    int f(int i,int fst,int n,vector<vector<int>>& boxes, int maxBoxes, int maxWeight){
        if(i == n)
            return 0;
        if(dp[i][fst]!=-1)
            return dp[i][fst];
        int prevprt = -1;
        int ans = 1e9;
        int cnt = 0;
        int curwt = 0;
        int curbx = 0;
        for(int j = i; j<n; j++){
            curwt += boxes[j][1];
            curbx++;
            if(curwt<=maxWeight && curbx<=maxBoxes){
                if(prevprt != boxes[j][0]){
                    if(fst!=0 && prevprt == -1)
                        cnt+=2;
                    else
                        cnt++;
                    ans = min(ans, cnt+f(j+1,1,n,boxes,maxBoxes,maxWeight));
                }else{
                    ans = min(ans, cnt+f(j+1,1,n,boxes,maxBoxes,maxWeight));
                }  
            }else{
                break;
            }
            prevprt = boxes[j][0];
        }
        return dp[i][fst] = ans;
    }
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        dp.resize(n,vector<int>(2,-1));
        return f(0,0,n,boxes,maxBoxes,maxWeight)+1;
    }
};




class Solution { // O(N) - Accepted
public:
    int boxDelivering(vector<vector<int>>& A, int portsCount, int B, int W) {
        int n = A.size(), need = 0, j = 0, lastj = 0;
        vector<int> dp(n + 1, 200000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && B > 0 && W >= A[j][1]) {
                B -= 1;
                W -= A[j][1];
                if (j == 0 || A[j][0] != A[j - 1][0]) {
                    lastj = j;
                    need++;
                }
                j++;
            }
            dp[j] = min(dp[j], dp[i] + need + 1);
            dp[lastj] = min(dp[lastj], dp[i] + need);
            B += 1;
            W += A[i][1];
            if (i == (n - 1) || A[i][0] != A[i + 1][0]) {
                need--;
            }
        }
        return dp[n];
    }
};