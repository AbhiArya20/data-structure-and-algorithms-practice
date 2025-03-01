#include<bits/stdc++.h>
using namespace std;

// GFG - Josephus Problem
// LeetCode - 1824
class Solution
{
    int helper(int n , int k){
        if(n==1)
            return 0;
        return (helper(n-1, k)+k)%n;
    }
    public:
    int josephus(int n, int k)
    {
       return helper(n,k)+1;
    }
};