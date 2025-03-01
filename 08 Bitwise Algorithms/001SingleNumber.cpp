#include<bits/stdc++.h>
using namespace std;

// LeetCode - 136

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xors = 0;
        for(int arr: nums)
            xors^=arr;
        return xors;
    }
};



// LeetCode - 260

class Solution{
public:
    vector<int> singleNumber(vector<int> nums) {
        long Xor = 0;
        for(auto v: nums)
            Xor^=v;
        long rms = Xor&(-Xor);
        int first = 0;
        int second = 0;
        for(auto v: nums){
            if(rms&v){
                first ^= v;
            }
        }
        second=Xor^first;
        if(first>second)
            swap(first,second);
        return {first,second};
    }
};