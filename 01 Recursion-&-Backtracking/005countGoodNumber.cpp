#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1922


/*
    1. Every even index has 5 posibility 0,2,4,6,8, So we can find using pow(5,(n+1)/2) 
    2. Every odd index has 4 posibility 2,3,5,7, So we can find using pow(4,n/2);
    3. multiple both even posiblity and odd posiblity

*/
class Solution {
    int mod = 1e9+7;
    long long int power(int v,long long int n){
        if(n==0)
            return 1;
        long long int temp = power(v,n/2);
        temp%=mod;
        if(n&1){
            return (v * ((temp * temp)%mod) )%mod;
        }
        return (temp * temp)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        long long ans1 = power(5,(n+1)/2)%mod;
        long long ans2 = power(4, n/2)%mod;
        return (int)((ans1*ans2)%mod);
    }
};