#include<bits/stdc++.h>
using namespace std;

// GFG - magic number

class Solution {
  int mod = 1e9+7;
  public:
    long long getVal(int N, int A[]) {
        int gcd = A[0];
        long long prod = A[0];
        for(int i = 1; i<N; i++){
            gcd=__gcd(gcd, A[i]);
            prod*=A[i];
            prod%=mod;
        } 
        return (long long)pow(prod,gcd)%mod;
    }
};