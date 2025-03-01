#include<bits/stdc++.h>
using namespace std;

// GFG - Lucky Number 

class Solution{
    bool islucky(int i,int n){
        if(n%i==0)
            return false;
        if(n<i)
            return true;
        return islucky(i+1,n-n/i);
    }
public:
    bool isLucky(int n) {
        return islucky(2,n);
    }
};