#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2442

class Solution {
    int reverseDigit(int value){
        int reversedValue = 0;
        while(value){
            reversedValue*=10;
            reversedValue+=value%10;
            value/=10;
        }
        return reversedValue;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> um;
        for(auto value: nums){
            um.insert(value);
            int reversedValue = reverseDigit(value);
            um.insert(reversedValue);
        }
        return um.size();
    }
};