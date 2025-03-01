#include<bits/stdc++.h>
using namespace std;

// GFG - Bike Racing

class Solution{
    bool pos(int mid, long N, long M, long L, long H[], long A[]){
        long sum = 0;
        for(int i = 0; i<N; i++){
            if(H[i]+mid*A[i]>=L)
                sum += H[i]+mid*A[i];
            if(sum>=M)
                return true;
        }
        return false;
    }
public:
    long buzzTime(long N, long M, long L, long H[], long A[]){
        long left = 0;
        long right = L+M;
        long ans = 0;
        while(left<=right){
            long mid = (left+right)>>1;
            if(pos(mid,N, M, L, H, A)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};