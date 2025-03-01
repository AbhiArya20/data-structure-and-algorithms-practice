#include<bits/stdc++.h>
using namespace std;

// LeetCode - 754
// GFG - Minimum steps to destination

class Solution{ // Not accepted O(2^n)
    int steps(int i, int d,int step){
        if(i == d)
            return step;
        if(i<(-d) || i>d)
            return INT_MAX;
        return min(steps(i+step+1,d,step+1), steps(i-step-1, d, step+1));
    }
public:
    int minSteps(int D){
        return steps(0,D,0);
    }
};



class Solution{ // Accepted O(n)
public:
    int minSteps(int D){
        int step = 0, sum = 0;
        while(sum<D || ((D-sum)&1)){
            step++;
            sum+=step;
        }
        return step;
    }
};