#include<bits/stdc++.h>
using namespace std;


// LeetCode - 390


/*
    1. Every time we reduce n/2 element from the array
       Each time step is multiply 2 times
    2. If we removing left to right then we always move forward
    3. If we removing right to left we remove first element if n%2==1 only

*/
class Solution {
    void lastRemaining(int n, int &ans, int step, bool isLeft){
        if(n <= 1)
            return;
        if(isLeft){
            ans+=step;
        }else if(n&1){
            ans+=step;
        }
        lastRemaining(n/2, ans,step*2,!isLeft);
    }
public:
    int lastRemaining(int n) {
        int ans = 1;
        lastRemaining(n, ans, 1,true);
        return ans;
    }
};