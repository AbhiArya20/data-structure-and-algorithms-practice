#include<bits/stdc++.h>
using namespace std;

// GFG - LCM

class Solution{
    int LCM(int a, int b){
        return (a*b)/__gcd(a,b);
    }
};


