#include<bits/stdc++.h>
using namespace std;

// GFG - Finding Position

class Solution {
  public:
    long long int nthPosition(long long int n){
        int ans = 1, step = 1;
        while(n>1){
            ans+=step;
            n/=2;
            step *= 2;
        }
        return ans;
    }
};