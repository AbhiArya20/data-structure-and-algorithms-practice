#include<bits/stdc++.h>
using namespace std;

// GFG - Tug of War 
// Practice - https://www.codingninjas.com/codestudio/problems/tug-of-war_985253

void subset(int i, vector<int> &arr, int n, int &ans, int first, int second, int fc, int sc){
    if(i==n){
        if(fc == n/2 || sc == n/2)
            ans = min(ans, abs(first-second));
        return;
    }
    subset(i+1,arr,n, ans,first+arr[i],second, fc+1, sc);
    subset(i+1,arr,n, ans,first,second+arr[i], fc, sc+1);
}
int tugOfWar(vector<int> &arr, int n)
{
    int ans = INT_MAX;
    subset(0,arr,n,ans, 0, 0, 0, 0);
    return ans;
}
