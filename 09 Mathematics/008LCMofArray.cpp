#include<bits/stdc++.h>
using namespace std;

// GFG - LCM of array

class Solution {
    int mod = 1e9+7;
  public:
    int lcmOfArray(int N , int A[]) {
        long long int lcm = A[0];
        for(int i = 1; i<N; i++){
            lcm = lcm*A[i]/__gcd(lcm, (long long int)A[i]);
            lcm %=mod;
        }
        return (int)lcm%mod;
    }
};