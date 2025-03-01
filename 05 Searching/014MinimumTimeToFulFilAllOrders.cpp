#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Time To Fulfil All Orders

class Solution{
    bool pos(int mid, int n, vector<int> &ar){
        int sum = 0;
        for(int i = 0; i<ar.size(); i++){
            int val = 2*mid/ar[i];
            int x = ((int)sqrt(1+4*val)-1)/2;
            sum+=x;
            if(sum>=n)
                return true;
        }
        return false;
    }
    public:
    int findMinTime(int N, vector<int>&A, int L){
        sort(A.begin(),A.end());
        long left = 0;
        long right = INT_MAX;
        int ans = 0;
        while(left<=right){
            int mid = (left+right)>>1;
            if(pos(mid,N, A)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
       return ans;
    }
};