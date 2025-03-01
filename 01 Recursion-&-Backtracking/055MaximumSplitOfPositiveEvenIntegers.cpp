#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2178

class Solution {
    bool getAns(long long finalSum, vector<long long> &temp, vector<long long> &ans, int prev){
        if(finalSum==0){
            if(ans.size()<temp.size())
                ans = temp;
            return true;
        }
        for(int i = prev+2; i<= finalSum; i+=2){
            temp.push_back(i);
            if(getAns(finalSum-i, temp, ans, i))
                return true;
            temp.pop_back();
        }
        return false;
    }
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum&1)
            return ans;
        vector<long long> temp;
        getAns(finalSum,temp,ans, 0);
        return ans;
    }
};