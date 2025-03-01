#include<bits/stdc++.h>
using namespace std;

// GFG - Friends Pairing Problem

class Solution
{
    int mod = 1e9+7;
public:
    int countFriendsPairings(int n) 
    { 
        if(n<=2)
            return n;
        long long prev = 2;
        long long secondPrev = 1;
        for(int i = 3; i<=n;i++){
            long long ans = (prev+(secondPrev*(i-1))%mod)%mod;
            secondPrev = prev;
            prev = ans;
        }
        return (int)prev;
    }
};    