#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1000

class Solution {
public:
    vector<int> prefixSum = {0};
    int memo[31][31];
    int rec(vector<int> &stones, int i, int j, int piles){
        if(i >= j) return 0;        
        if(memo[i][j] != -1) return memo[i][j];        
        int mini = INT_MAX;
        for(int k = i; k < j; k = k+piles-1){
            int tempAns = rec(stones, i, k, piles) + rec(stones, k+1, j, piles);
            mini = min(tempAns, mini);
        }
        if((j-i)%(piles-1) == 0){
            mini += prefixSum[j+1] - prefixSum[i];
        }        
        return memo[i][j] = mini;
    }
    int mergeStones(vector<int>& stones, int k){
        int n = stones.size();
        if((n-1)%(k-1) != 0) return -1;        
        for(int i : stones) prefixSum.emplace_back(prefixSum.back() + i);        
        memset(memo, -1, sizeof(memo));
        return rec(stones, 0, n-1, k);
    }
}; 