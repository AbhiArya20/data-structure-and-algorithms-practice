#include<bits/stdc++.h>
using namespace std;


// LeetCode - 326
class Solution {
    // long long to avoid integer overflow situations
    bool isPowOf3(long long now, int n){
        if(n==now)
            return true;
        if(now>n)
            return false;
        return isPowOf3(now*3,n);
    }
public:
    bool isPowerOfThree(int n) {
        // negative numbers cannot be a power of positive number so we are not going to check for negative number
        return isPowOf3(1,n);
    }
};