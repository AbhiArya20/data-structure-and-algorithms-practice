#include<bits/stdc++.h>
using namespace std;

// GFG - Square Root of a Number 

class Solution{
  public:
    long long int floorSqrt(long long int x) {
        long long int ans = 0;
        long long int left = 0;
        long long int right = x;
        while(left<=right){
            long long int mid = (left+right)>>1;
            if(mid*mid<=x){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};