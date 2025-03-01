#include<bits/stdc++.h>
using namespace std;

// LeetCode - 50

class Solution {
    double power(double v,int n){
        if(n==0)
            return 1;
        double temp = power(v,n/2);
        if(n&1){
            if(n>0)
                return v * temp * temp;
            return (temp * temp) / v;
        }
        return temp * temp;
    }
public:
    double myPow(double x, int n) {
        return power(x,n);
    }
};



class Solution{ // Iterative - for positive power
    public:
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};