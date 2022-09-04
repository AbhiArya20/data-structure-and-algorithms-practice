#include<bits/stdc++.h>
using namespace std;

// GFG - Steping Numbers

class Solution{
    void dfs(int cur, int &ans, int n, int m){
        if(cur>=n && cur<=m)
            ans++;
        int lst = cur%10;
        if(lst+1<=9 && cur*10+(lst+1)<=m){
            dfs(cur*10+(lst+1), ans, n, m);
        }
        if(lst-1>=0 && cur*10+(lst-1)<=m){
            dfs(cur*10+(lst-1), ans, n, m);
        }
    }
public:

    int steppingNumbers(int n, int m)
    {
        int ans = 0;
        if(m<10){
            return m-n+1;
        }
        if(n==0)
            ans++;
        for(int i = 1;i<=9; i++){
            dfs(i, ans, n, m);
        }
        return ans;
    }
};