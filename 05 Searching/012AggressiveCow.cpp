#include<bits/stdc++.h>
using namespace std;

// GFG - Aggressive Cow

class Solution {
    bool pos(int mid, vector<int> &stalls, int k){
        int n = stalls.size();
        int cow = 1; 
        int prev = stalls[0];
        for(int i = 1; i<n; i++){
            if(stalls[i]-prev>=mid){
                cow++;
                prev = stalls[i];
            }
        }
        return cow>=k;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int left = 1;
        int right = *max_element(stalls.begin(), stalls.end())+1;
        int ans = 0;
        while(left<=right){
            int mid = (left+right)>>1;
            if(pos(mid,stalls,k)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};