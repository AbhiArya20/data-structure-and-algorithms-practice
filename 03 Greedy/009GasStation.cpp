#include<bits/stdc++.h>
using namespace std;

// LeetCode - 134

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        if(totalCost>totalGas)
            return -1;
        int n = gas.size();
        int ans = 0;
        totalCost = totalGas = 0;
        for(int i = 0; i<n-1; i++){
            totalCost += cost[i];
            totalGas += gas[i];
            if(totalCost>totalGas){
                ans = i+1;
                totalCost = totalGas = 0;
            }
        }
        return ans;
    }
};