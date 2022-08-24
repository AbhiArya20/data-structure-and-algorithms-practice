#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Number of Jumps

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<=1)
            return 0;
        if(arr[0]==0)
            return -1;
        int ans = 1, step = arr[0], maxi = arr[0];
        for(int i = 1; i<n; i++){
            if(i == n-1)
                return ans;
            maxi = max(maxi, i+arr[i]);
            step--;
            if(i>=maxi)
                return -1;
            if(!step){
                ans++;
                step = maxi-i;
            }
        }   
        return -1;
    }
};